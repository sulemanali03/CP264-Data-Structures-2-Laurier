/**
 * -------------------------------------
 * @file  functions.c
 * Lab 2 Functions Source Code File
 * -------------------------------------
 * @author Suleman Ali, 169044667, alix4667@mylaurier.ca
 *
 * @version 2023-09-09
 *
 * -------------------------------------
 */
#include "functions.h"

int sum_three_integers(void) {
	int num1, num2, num3;
	char input[STRING_BIG];

	while (1) {
		printf("Enter three comma-separated integers: ");
		fgets(input, STRING_BIG, stdin);

		// Parse input for exactly 3 comma-separated integers
		if (sscanf(input, "%d,%d,%d", &num1, &num2, &num3) == 3) {
			return num1 + num2 + num3;
		} else {
			printf("The integers were not properly entered.\n");
		}
	}
}
