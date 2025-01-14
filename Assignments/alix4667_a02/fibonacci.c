/*
 -------------------------------------
 File:    fibonacci.c
 Project: a2
 file description
 -------------------------------------
 Author:  Suleman Ali
 ID:      169044667
 Email:   alix4667@mylaurier.ca
 Version  2024-01-22
 -------------------------------------
 */

#include "fibonacci.h"

int iterative_fibonacci(int n) {
	if (n <= 1)
		return n;

	int prev = 0, current = 1, next;
	for (int i = 2; i <= n; ++i) {
		next = prev + current;
		prev = current;
		current = next;
	}

	return current;
}

int recursive_fibonacci(int n) {
	if (n <= 1)
		return n;

	return recursive_fibonacci(n - 1) + recursive_fibonacci(n - 2);
}

int dpbu_fibonacci(int *f, int n) {
	if (n < 0)
		return -3;
	if (n <= 1)
		return n;

	f[0] = 0;
	f[1] = 1;
	for (int i = 2; i <= n; ++i) {
		f[i] = f[i - 2] + f[i - 1];
	}

	return f[n];
}

int dptd_fibonacci(int *f, int n) {
	if (n < 0)
		return -3;
	if (n <= 1)
		return n;

	if (f[n] != -1)
		return f[n];

	f[n] = dptd_fibonacci(f, n - 2) + dptd_fibonacci(f, n - 1);
	return f[n];
}

