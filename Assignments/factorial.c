/*
 -------------------------------------
 File:    factorial.c
 Project: alix4667_a01
 file description
 -------------------------------------
 Author:  Suleman Ali
 ID:      169044667
 Email:   alix4667@mylaurier.ca
 Version  2024-01-20
 -------------------------------------
 */

#include "factorial.h"

/**
 * Compute the factorial n! and does overflow detection.
 */
int factorial(int n) {
	int f = 1;
	if (n >= 1) {
		for (int i = 1; i <= n; ++i) {
			int temp = f;
			f = f * i;
			// Overflow detection
			if (temp != f / i) {
				return 0; // Overflow occurred
			}
		}
	}
	return f;
}
