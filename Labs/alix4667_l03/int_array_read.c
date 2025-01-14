/**
 * -------------------------------------
 * @file  int_array_read.c
 * Lab 3 Source Code File
 * -------------------------------------
 * @author Suleman Ali, 169044667, alix4667@mylaurier.ca
 *
 * @version 2024-01-25
 *
 * -------------------------------------
 */
#include "functions.h"

void int_array_read(int *array, int size) {
	int i = 0;
	char input[STRING_BIG];
	int num;

	printf("Enter %d values for an array of int.\n", size);
	while (i < size) {
		printf("Value for index %d: ", i);
		fgets(input, STRING_BIG, stdin);

		if (sscanf(input, "%d", &num) == 1) {
			array[i] = num;
			i++;
		} else {
			printf("Not a valid integer\n");
		}
	}
}
