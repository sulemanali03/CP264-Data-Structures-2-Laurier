/*
 -------------------------------------
 File:    mychar.c
 Project: alix4667_a01
 file description
 -------------------------------------
 Author:  Suleman Ali
 ID:      169044667
 Email:   alix4667@mylaurier.ca
 Version  2024-01-20
 -------------------------------------
 */

#include "mychar.h"

/**
 * Determine the type of a char character.
 */
int mytype(char c) {
	if (c >= '0' && c <= '9') {
		return 0;
	} else if (c == '+' || c == '-' || c == '*' || c == '/') {
		return 1;
	} else if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) {
		return 2;
	} else {
		return -1;
	}
}

/**
 * Flip the case of an English character.
 */
char case_flip(char c) {
	if (c >= 'a' && c <= 'z') {
		return c - 'a' + 'A';
	} else if (c >= 'A' && c <= 'Z') {
		return c - 'A' + 'a';
	} else {
		return c; // Return the character as is if it's not an English letter
	}
}

/**
 * Convert digit character to the corresponding integer value.
 */
int char_to_int(char c) {
	if (c >= '0' && c <= '9') {
		return c - '0';
	} else {
		return -1; // Return -1 if it's not a digit
	}
}
