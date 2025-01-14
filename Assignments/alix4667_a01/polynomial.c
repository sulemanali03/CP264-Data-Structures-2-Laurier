/*
 -------------------------------------
 File:    polynomial.c
 Project: a2
 file description
 -------------------------------------
 Author:  Suleman Ali
 ID:      169044667
 Email:   alix4667@mylaurier.ca
 Version  2024-01-22
 -------------------------------------
 */

#include "polynomial.h"
#include <math.h>
#include <stdio.h>

float horner(float p[], int n, float x) {
	float result = p[0]; // Start with the constant term

	for (int i = 1; i < n; ++i) {
		result = result * x + p[i];
	}

	return result;
}

float bisection(float p[], int n, float a, float b) {
	if (horner(p, n, a) * horner(p, n, b) > 0)
		return -3; // No guarantee of root in the interval

	float c = (a + b) / 2.0;

	while (fabs(b - a) > 1e-6 && fabs(horner(p, n, c)) > 1e-6) {
		if (horner(p, n, c) * horner(p, n, a) < 0)
			b = c;
		else
			a = c;

		c = (a + b) / 2.0;
	}

	return c;
}
