/**
 * -------------------------------------
 * @file  sum_integers.c
 * Lab 3 Source Code File
 * -------------------------------------
 * @author Suleman Ali, 169044667, alix4667@mylaurier.ca
 *
 * @version 2024-01-25
 *
 * -------------------------------------
 */

#include "functions.h"

int sum_integers(void) {
	int sum = 0;
	int num;
	char input[STRING_SMALL];

	printf("Enter integers, one per line:\n");
	while (fgets(input, STRING_SMALL, stdin)) {
		if (sscanf(input, "%d", &num) == 1) {
			sum += num;
		} else {
			break;  // Stop reading if a non-integer is entered
		}
	}

	return sum;
}
