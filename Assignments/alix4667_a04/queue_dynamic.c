/**
 * -------------------------------------
 * @file  queue_dynamic.c
 * Dynamic Queue Source Code File
 * -------------------------------------
 * @author name, id, email
 *
 * @version 2024-10-05
 *
 * -------------------------------------
 */
#include "queue_dynamic.h"

// Functions

// Initializes a queue.
void queue_initialize(queue_dynamic_struct **source, int capacity) {
	*source = malloc(sizeof(queue_dynamic_struct));
	assert(*source != NULL);  // Check if memory allocation is successful
	(*source)->capacity = capacity;
	(*source)->count = 0;
	(*source)->front = 0;
	(*source)->rear = -1;
	(*source)->items = malloc(capacity * sizeof(data_type));
	assert((*source)->items != NULL);
}

// Destroys a queue.
void queue_destroy(queue_dynamic_struct **source) {
	free((*source)->items);
	free(*source);
	*source = NULL;
}

// Determines if a queue is empty.
bool queue_empty(const queue_dynamic_struct *source) {
	return source->count == 0;
}

// Determines if the queue is full.
bool queue_full(const queue_dynamic_struct *source) {
	return false;
}

// Returns the number of items in the queue.
int queue_count(const queue_dynamic_struct *source) {
	return source->count;
}

// Inserts an item into a queue.
bool queue_insert(queue_dynamic_struct *source, data_type *item) {
	if (queue_full(source)) {
		return false;
	}
	source->rear = (source->rear + 1) % source->capacity;
	source->items[source->rear] = *item;
	source->count++;
	return true;
}

// Returns a copy of the front of a queue.
bool queue_peek(const queue_dynamic_struct *source, data_type *item) {
	if (queue_empty(source)) {
		return false;
	}
	*item = source->items[source->front];
	return true;
}

// Returns and removes the item on the front of a queue.
bool queue_remove(queue_dynamic_struct *source, data_type *item) {
	if (queue_empty(source)) {
		return false;
	}
	*item = source->items[source->front];
	source->front = (source->front + 1) % source->capacity;
	source->count--;
	return true;
}

void queue_print(const queue_dynamic_struct *source) {
	// Walk through queue from front to rear using indexes.
	int temp = source->front;

	for (int i = 0; i < source->count; i++) {
		data_print(&(source->items[temp]));
		printf("\n");
		temp = (temp + 1) % source->capacity;
	}
	return;
}
