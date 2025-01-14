/**
 * -------------------------------------
 * @file  pq_dynamic.c
 * Dynamic Priority Queue Source Code File
 * -------------------------------------
 * @author name, id, email
 *
 * @version 2024-10-05
 *
 * -------------------------------------
 */
#include "pq_dynamic.h"

// Functions

// Initializes a priority queue.
void pq_initialize(pq_dynamic_struct **source, int capacity) {
	*source = malloc(sizeof(pq_dynamic_struct));
	assert(*source != NULL);  // Check for allocation success
	(*source)->capacity = capacity;
	(*source)->count = 0;
	(*source)->first = -1;
	(*source)->items = malloc(capacity * sizeof(data_type));
	assert((*source)->items != NULL);
}

// Destroys a priority queue.
void pq_destroy(pq_dynamic_struct **source) {
	free((*source)->items);
	free(*source);
	*source = NULL;
}

// Determines if a priority queue is empty.
bool pq_empty(const pq_dynamic_struct *source) {
	return source->count == 0;
}

// Determines if the queue is full.
bool pq_full(const pq_dynamic_struct *source) {
	return false;
}

// Returns the number of items in the queue.
int pq_count(const pq_dynamic_struct *source) {
	return source->count;
}

// Inserts an item into a priority queue.
bool pq_insert(pq_dynamic_struct *source, data_type *item) {
	if (pq_full(source)) {
		return false;
	}

	int i = source->count - 1;
	while (i >= 0 && data_compare(&source->items[i], item) < 0) {
		source->items[i + 1] = source->items[i];
		i--;
	}

	source->items[i + 1] = *item;
	source->count++;
	source->first = 0;  // Update first to highest priority item
	return true;
}

// Returns a copy of the first of a priority queue.
bool pq_peek(const pq_dynamic_struct *source, data_type *item) {
	if (pq_empty(source)) {
		return false;
	}
	*item = source->items[source->first];
	return true;
}

// Returns and removes the item on the first of a priority queue.
bool pq_remove(pq_dynamic_struct *source, data_type *item) {
	if (pq_empty(source)) {
		return false;
	}
	*item = source->items[source->first];
	for (int i = 0; i < source->count - 1; i++) {
		source->items[i] = source->items[i + 1];
	}
	source->count--;
	source->first = (source->count == 0) ? -1 : 0;  // Reset if empty
	return true;
}

// Prints the items in a priority queue from first to rear.
void pq_print(const pq_dynamic_struct *source) {
// Walk through stack from top to bottom using indexes.
	for (int i = 0; i < source->count; i++) {
		data_print(&(source->items[i]));
		printf("\n");
	}
	return;
}
