/*
 -------------------------------------
 File:    mychar.h
 Project: alix4667_a01
 file description
 -------------------------------------
 Author:  Suleman Ali
 ID:      169044667
 Email:   alix4667@mylaurier.ca
 Version  2024-01-20
 -------------------------------------
 */

#ifndef MYCHAR_H
#define MYCHAR_H

#include <stdio.h>

/**
 * Determine the type of a char character.
 *
 * @param c - char type value
 * @return - 0 if c is a digit, 1 if c is an arithmetic operator, 2 if c is an English letter; otherwise -1.
 */
int mytype(char c);

/**
 * Flip the case of an English character.
 *
 * @param c - char type value of ASCII code of English letter.
 * @return - c's upper/lower case letter if c is a lower/upper case English letter.
 */
char case_flip(char c);

/**
 * Convert digit character to the corresponding integer value.
 *
 * @param c - char type value of ASCII code of digit character.
 * @return - its corresponding integer value if c is a digit character.
 */
int char_to_int(char c);

#endif
