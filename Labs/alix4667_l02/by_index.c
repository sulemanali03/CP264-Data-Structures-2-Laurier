/**
 * -------------------------------------
 * @file  by_index.c
 * Lab 2 Index Functions Source Code File
 * -------------------------------------
 * @author Suleman Ali, 169044667, alix4667@mylaurier.ca
 *
 * @version 2024-01-06
 *
 * -------------------------------------
 */
#include "by_index.h"

void fill_values_by_index(int values[], int size) {

	for (int i = 0; i < size; i++) {
		values[i] = i + 1;
	}
}

void fill_squares_by_index(int values[], long int squares[], int size) {
	for (int i = 0; i < size; i++) {
		squares[i] = (long int) values[i] * values[i];
	}
}

void print_by_index(int values[], long int squares[], int size) {
	printf("Value\tSquare\n");
	for (int i = 0; i < size; i++) {
		printf("%d\t%ld\n", values[i], squares[i]);
	}
}

