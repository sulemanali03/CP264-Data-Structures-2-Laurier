/**
 * -------------------------------------
 * @file  strings_length.c
 * Lab 4 Source Code File
 * -------------------------------------
 * @author Suleman Ali, 169044667, alix4667@mylaurier.ca
 *
 * @version 2024-02-03
 *
 * -------------------------------------
 */
#include "functions.h"

void strings_length(strings_array *data, FILE *fp_short, FILE *fp_long,
		int length) {
	// Loop through each string in the array
	for (int i = 0; i < data->lines; i++) {
		// Compare the length of the current string
		if (strlen(data->strings[i]) < length) {
			// Write to the short file if string length is less than the specified length
			fprintf(fp_short, "%s\n", data->strings[i]);
		} else {
			// Write to the long file if string length is equal to or greater than the specified length
			fprintf(fp_long, "%s\n", data->strings[i]);
		}
	}
}
