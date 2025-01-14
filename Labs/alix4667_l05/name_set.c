/**
 * -------------------------------------
 * @file  name_set_initialize.c
 * Lab 5 Source Code File
 * -------------------------------------
 * @author Heider Ali, 999999999, heali@wlu.ca
 * @author David Brown, 123456789, dbrown@wlu.ca
 *
 * @version 2024-02-09
 *
 * -------------------------------------
 */
#include "name_set.h"

name_set* name_set_initialize() {
	// Allocate memory to the data structure
	name_set *set = malloc(sizeof *set);
	// Initialize the header fields.
	set->front = NULL;
	set->rear = NULL;
	return set;
}

int name_set_free(name_set **set) {
	if (*set == NULL) {
		return 0;
	}
	int count = 0;
	name_set_node *current = (*set)->front;
	name_set_node *next_node = NULL;

	// Traverse and free each node
	while (current != NULL) {
		next_node = current->next;
		free(current);
		current = next_node;
		count++;
	}

	// Free the set itself
	free(*set);
	*set = NULL;
	return count;
}

BOOLEAN name_set_append(name_set *set, const char *first_name,
		const char *last_name) {
	// Check if the name is already in the set
	if (name_set_contains(set, first_name, last_name)) {
		return FALSE;  // Name already exists
	}

	// Create a new node
	name_set_node *new_node = malloc(sizeof *new_node);
	strncpy(new_node->first_name, first_name, NAME_LEN);
	strncpy(new_node->last_name, last_name, NAME_LEN);
	new_node->next = NULL;

	// Insert the node at the end of the list
	if (set->rear == NULL) {
		// Empty list
		set->front = new_node;
		set->rear = new_node;
	} else {
		// Append to the rear
		set->rear->next = new_node;
		set->rear = new_node;
	}

	return TRUE;
}

BOOLEAN name_set_contains(const name_set *set, const char *first_name,
		const char *last_name) {
	name_set_node *current = set->front;

	while (current != NULL) {
		if (strncmp(current->first_name, first_name, NAME_LEN) == 0
				&& strncmp(current->last_name, last_name, NAME_LEN) == 0) {
			return TRUE;  // Name found
		}
		current = current->next;
	}

	return FALSE;  // Name not found
}

void name_set_print(const name_set *set) {
	name_set_node *current = set->front;

	while (current != NULL) {
		printf("%s, %s\n", current->last_name, current->first_name);
		current = current->next;
	}
}

