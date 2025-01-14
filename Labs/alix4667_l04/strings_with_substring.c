/**
 * -------------------------------------
 * @file  strings_with_substring.c
 * Lab 4 Source Code File
 * -------------------------------------
 * @author Suleman Ali, 169044667, alix4667@mylaurier.ca
 *
 * @version 2024-02-03
 *
 * -------------------------------------
 */
#include "functions.h"

void strings_with_substring(strings_array *data, char *substr) {
	// Loop through each string in the array
	for (int i = 0; i < data->lines; i++) {
		// Use strstr to find the substring within the current string
		if (strstr(data->strings[i], substr) != NULL) {
			// Print the string if the substring is found
			printf("%s\n", data->strings[i]);
		}
	}
}
