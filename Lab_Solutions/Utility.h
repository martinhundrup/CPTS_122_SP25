/*
 * File: Utility.h
 * Author: Martin Hundrup
 * Professor: Andy O'Fallon
 * Class: CPT_S 121, Fall 2024
 * Assignment: Lab 10
 * Created: October 30, 2024
 * Last Updated: October 30, 2024
 */

#ifndef UTILITY_H
#define UTILITY_H

#define _CRT_SECURE_NO_WARNINGS

 // for colored text
#define BLK "\033[0;30m"
#define RED "\033[0;31m"
#define GRN "\033[0;32m"
#define YEL "\033[0;33m"
#define BLU "\033[0;34m"
#define MAG "\033[0;35m"
#define CYN "\033[0;36m"
#define WHT "\033[0;37m"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>	// isdigit()
#include <string.h>	// strtok()

/*
	Clears the stdin buffer.
	source: https://www.geeksforgeeks.org/clearing-the-input-buffer-in-cc/
*/
static inline void clear_buffer() {

	// flushes the standard input
	// (clears the input buffer)
	while ((getchar()) != '\n');
}

/*
	Gets an integer from the user.

	@return the value entered in stdin
*/
static inline int get_int() {

	int input = 0;
	scanf("%d", &input);
	clear_buffer();
	return input;
}

/*
	Gets an character from the user.

	@return the value entered in stdin
*/
static inline char get_char() {

	char input = 0;
	scanf("%c", &input);
	clear_buffer();
	return input;
}

/*
	Clears terminal lines.

	@param the number of lines to clear
*/
static inline void clear_lines(int n) {

	for (int i = 0; i < n; i++) {
		printf("\033[1A");
		printf("\r\033[K");
	}
}

/*
	Generates a random integer between [min, max]

	@param min inclusive
	@param max inclusive

	@return the random value
*/
static inline int random_range(int min, int max) {

	return (rand() % ((max + 1) - min)) + min;
}

/*
	removes all instances of a desired target character in a string

	@param the string to parse
	@param the target character to remove

	@return the pointer to the str
*/
static inline char* remove_char(char* str, char target) {

	int read = 0, write = 0;

	while (str[read]) {
		if (str[read] != target) {
			str[write++] = str[read];
		}
		read++;
	}

	str[write] = '\0';
}

#endif

