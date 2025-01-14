/**
 * -------------------------------------
 * @file  list_dynamic.c
 * Dynamic List Source Code File
 * -------------------------------------
 * @version 2024-10-05
 * -------------------------------------
 */
#include "list_dynamic.h"

// Private helper functions

/**
 * Determines if an index is valid.
 */
static bool valid_index(const list_dynamic_struct *source, int i) {
	return ((i >= 0) && (i < source->count));
}

/**
 * Performs a linear search on source->items for key.
 */
static int list_linear_search(const list_dynamic_struct *source,
		const data_type *key) {
	for (int i = 0; i < source->count; i++) {
		if (data_compare(&(source->items[i]), key) == 0) {
			return i;
		}
	}
	return -1;
}

// Functions

// Initializes a list.
void list_initialize(list_dynamic_struct **source, int capacity) {
	*source = (list_dynamic_struct*) malloc(sizeof(list_dynamic_struct));
	(*source)->items = (data_type*) malloc(capacity * sizeof(data_type));
	(*source)->capacity = capacity;
	(*source)->count = 0;
}

// Destroys a list.
void list_destroy(list_dynamic_struct **source) {
	free((*source)->items);
	free(*source);
	*source = NULL;
}

// Determines if a list is empty.
bool list_empty(const list_dynamic_struct *source) {
	return source->count == 0;
}

// Determines if the list is full.
bool list_full(const list_dynamic_struct *source) {
	return source->count == source->capacity;
}

// Appends an item to the end of a list.
bool list_append(list_dynamic_struct *source, data_type *item) {
	if (list_full(source)) {
		source->capacity *= 2;
		source->items = realloc(source->items,
				source->capacity * sizeof(data_type));
	}
	source->items[source->count] = *item;
	source->count++;
	return true;
}

// Returns the number of items in the list.
int list_count(const list_dynamic_struct *source) {
	return source->count;
}

// Inserts an item to a list at location i.
bool list_insert(list_dynamic_struct *source, data_type *item, int i) {
	if (!valid_index(source, i) || list_full(source))
		return false;

	if (list_full(source)) {
		source->capacity *= 2;
		source->items = realloc(source->items,
				source->capacity * sizeof(data_type));
	}
	for (int j = source->count; j > i; j--) {
		source->items[j] = source->items[j - 1];
	}
	source->items[i] = *item;
	source->count++;
	return true;
}

// Returns a copy of the front of a list.
bool list_peek(const list_dynamic_struct *source, data_type *item) {
	if (list_empty(source))
		return false;
	*item = source->items[0];
	return true;
}

// Returns a copy of the item matching key in a list.
bool list_key_find(const list_dynamic_struct *source, const data_type *key,
		data_type *item) {
	int index = list_linear_search(source, key);
	if (index == -1)
		return false;
	*item = source->items[index];
	return true;
}

// Removes and returns the item matching key from the list.
bool list_key_remove(list_dynamic_struct *source, const data_type *key,
		data_type *item) {
	int index = list_linear_search(source, key);
	if (index == -1)
		return false;
	*item = source->items[index];
	for (int j = index; j < source->count - 1; j++) {
		source->items[j] = source->items[j + 1];
	}
	source->count--;
	return true;
}

// Returns the index of key in list. -1 if key not in list.
int list_key_index(const list_dynamic_struct *source, const data_type *key) {
	return list_linear_search(source, key);
}

// Determines if key is in a list.
bool list_key_contains(const list_dynamic_struct *source, const data_type *key) {
	return list_linear_search(source, key) != -1;
}

// Determines number of times key appears in list.
int list_key_count(const list_dynamic_struct *source, const data_type *key) {
	int count = 0;
	for (int i = 0; i < source->count; i++) {
		if (data_compare(&(source->items[i]), key) == 0) {
			count++;
		}
	}
	return count;
}

// Removes and returns the item at index i from a list.
bool list_index_remove(list_dynamic_struct *source, data_type *item, int i) {
	if (!valid_index(source, i))
		return false;
	*item = source->items[i];
	for (int j = i; j < source->count - 1; j++) {
		source->items[j] = source->items[j + 1];
	}
	source->count--;
	return true;
}

// Finds the maximum item in a list.
bool list_max(const list_dynamic_struct *source, data_type *item) {
	if (list_empty(source))
		return false;
	*item = source->items[0];
	for (int i = 1; i < source->count; i++) {
		if (data_compare(&(source->items[i]), item) > 0) {
			*item = source->items[i];
		}
	}
	return true;
}

// Finds the minimum item in a list.
bool list_min(const list_dynamic_struct *source, data_type *item) {
	if (list_empty(source))
		return false;
	*item = source->items[0];
	for (int i = 1; i < source->count; i++) {
		if (data_compare(&(source->items[i]), item) < 0) {
			*item = source->items[i];
		}
	}
	return true;
}

// Removes all duplicate items from a list.
void list_clean(list_dynamic_struct *source) {
	for (int i = 0; i < source->count; i++) {
		for (int j = i + 1; j < source->count;) {
			if (data_compare(&(source->items[i]), &(source->items[j])) == 0) {
				list_index_remove(source, NULL, j);
			} else {
				j++;
			}
		}
	}
}

// Compares two lists for equality.
bool list_equal(const list_dynamic_struct *target,
		const list_dynamic_struct *source) {
	if (target->count != source->count)
		return false;
	for (int i = 0; i < source->count; i++) {
		if (data_compare(&(target->items[i]), &(source->items[i])) != 0) {
			return false;
		}
	}
	return true;
}

// Prints the items in a list from front to rear.
void list_print(const list_dynamic_struct *source) {
	for (int i = 0; i < source->count; i++) {
		data_print(&(source->items[i]));
		printf("\n");
	}
}
