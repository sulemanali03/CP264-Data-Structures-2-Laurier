/**
 * -------------------------------------
 * @file  queue_array.c
 * queue_array Source Code File
 * -------------------------------------
 * @author Suleman Ali,169044667, alix4667@mylaurier.ca
 *
 * @version 2024-09-28
 *
 * -------------------------------------
 */
#include "queue_array.h"

void queue_initialize(queue_struct *source) {
	source->capacity = QUEUE_INIT;
	source->count = 0;
	source->front = 0;
	source->rear = -1;
}

bool queue_empty(const queue_struct *source) {
	return source->count == 0;
}

bool queue_full(const queue_struct *source) {
	return source->count == source->capacity;
}

int queue_count(const queue_struct *source) {
	return source->count;
}

bool queue_insert(queue_struct *source, data_type *item) {
	if (queue_full(source)) {
		return false;
	}

	source->rear = (source->rear + 1) % source->capacity;
	source->items[source->rear] = *item;
	source->count++;
	return true;
}

bool queue_peek(const queue_struct *source, data_type *item) {
	if (queue_empty(source)) {
		return false;
	}

	*item = source->items[source->front];
	return true;
}

bool queue_remove(queue_struct *source, data_type *item) {
	if (queue_empty(source)) {
		return false;
	}

	*item = source->items[source->front];
	source->front = (source->front + 1) % source->capacity;
	source->count--;
	return true;
}

void queue_print(const queue_struct *source) {
	for (int i = 0; i < source->count; i++) {
		int index = (source->front + i) % source->capacity;
		data_print(&source->items[index]);
		printf("\n");
	}
}
