/*
 * File: lab1.c
 * Author: Martin Hundrup
 * Professor: Andy O'Fallon
 * Class: CPT_S 122, Spring 2024
 * Assignment: Lab 1
 * Created: January 14, 2025
 */

#include "lab1.h"

// mirrors layout in the corresponding .h file
#pragma region Task 1

void task_1() {

	printf("hello, world!\n");
}

#pragma endregion

#pragma region Task 2

void task_2() {

	printf("task 2:\n");

	char s[100] = "hello";
	char s2[100] = ", world!";

	printf("destination prior to strcat(): %s\n", s);
	printf("source prior to strcat(): %s\n", s2);
	my_strcat(s, s2);
	printf("destination after strcat(): %s\n", s);


	// string literal is read-only
	// char* _str = "hello";
	// so we must use a char array
	char _str[100] = "hello,.,cpts.,.122!";

	printf("string before recursive string reverse: %s\n", _str);
	recursive_string_reverse(_str);
	printf("string after recursive string reverse: %s\n\n", _str);
	recursive_string_reverse(_str);

	printf("strtok returned: %s\n", my_strtok(_str, ",."));
	for (int i = 0; i < 9; i++) {

		printf("strtok returned: %s\n", my_strtok(NULL, ",."));
	}


	printf("\nMerge n' sort 1:");
	char dest[100] = { '\0' };
	str_mergensort_so1l("apple", "orange", dest, 99);
	printf("\nstring 1: %s\n", "apple");
	printf("string 2: %s\n", "orange");
	printf("mergensorted: %s\n", dest);

	printf("\nMerge n' sort 2:");
	printf("\nstring 1: %s\n", "apple");
	printf("string 2: %s\n", "orange");
	printf("mergensorted: %s\n", str_mergensort_sol2("apple", "orange"));

	printf("\nMerge n' sort 3:");
	char str1[100] = "apple";
	printf("\nstring 1: %s\n", str1);
	printf("string 2: %s\n", "orange");
	str_mergensort_sol3(str1, "orange", 99);
	printf("mergensorted: %s\n", str1);
}

char* my_strcat(char* destination, const char* source) {

	// find end of destination
	int end = strlen(destination);

	// append
	int i = 0;
	for (; source[i] != '\0'; i++) {
		destination[i + end] = source[i];
	}

	// append null character
	destination[i + end] = '\n';
	return destination;
}

void recursive_string_reverse(char* str) {

	static char* _str = NULL;
	static int i = 0;

	// new call to func
	if (str != _str) {

		i = 0;
		_str = str;
	}

	int len = strlen(str);

	// base case: the middle of the string was reached
	if (i >= len / 2) {

		_str = NULL;
		return;
	}

	// swap
	char t = str[i];
	str[i] = str[len - i - 1];
	str[len - i - 1] = t;

	// increment and recurse
	i++;
	recursive_string_reverse(str);
}

char* my_strtok(char* str, char* delims) {

	static char* _str = NULL;

	// start tokenizing this string
	if (str != NULL)
		_str = str;
	else
		str = _str;

	int d_len = strlen(delims);

	// back to back delim
	for (int i = 0; i < d_len; i++) {

		if (*_str == delims[i]) {

			*_str = '\0';
			_str++;
			return NULL;
		}
	}

	if (*_str == '\0') // end of string
		return NULL;

	while (*_str != '\0') {

		for (int i = 0; i < d_len; i++) {

			if (*_str == delims[i]) {

				*_str = '\0';
				_str++;
				return str;
			}
		}

		_str++;
	}

	// end of string for first time
	return str;
}

void str_mergensort_so1l(char* str1, char* str2, char* dest, int len) {

	// there's probably a better way to go about this but this suffices

	int ascii_histogram[128] = { 0 }; // a histogram representing all the ascii appearances in the two strings
	int dest_counter = 0;

	for (int i = 0; i < strlen(str1); i++) { // loop through each char in str1

		ascii_histogram[str1[i]]++; // add to the histogram if a character is present
	}
	for (int i = 0; i < strlen(str2); i++) { // loop through each char in str2

		ascii_histogram[str2[i]]++;// add to the histogram if a character is present
	}

	for (int i = 0; i < 128; i++) { // this loops through our histogram and inserts the amount of characters present into the destination string

		for (int j = 0; j < ascii_histogram[i] && dest_counter < len; j++) {

			dest[dest_counter] = i;
			dest_counter++;
		}
	}

	dest[dest_counter] = '\0'; // insert null character at the end	
}

char* str_mergensort_sol2(char* str1, char* str2) {

	int ascii_histogram[128] = { 0 }; // a histogram representing all the ascii appearances in the two strings
	int dest_counter = 0;

	for (int i = 0; i < 128; i++) {

		for (int j = 0; j < strlen(str1); j++) { // loop through each char in str1

			if (str1[j] == i)
				ascii_histogram[i]++; // add to the histogram if a character is present
		}
		for (int j = 0; j < strlen(str2); j++) { // loop through each char in str2

			if (str2[j] == i)
				ascii_histogram[i]++; // add to the histogram if a character is present
		}
	}

	// we will use realloc() each time a new character is inserted
	char* destination = (char*)malloc(sizeof(char));

	for (int i = 0; i < 128; i++) {

		for (int j = 0; j < ascii_histogram[i]; j++) {
			destination = (char*)realloc(destination, sizeof(char) * (dest_counter + 1)); // make sure we add one more space for the new character
			//destination = temp;
			destination[dest_counter] = i; // ignore the warning the compiler doesn't know what it's talking about
			dest_counter++;
		}
	}

	destination[dest_counter] = '\0'; // insert null character at the end
	return destination;
}

char* str_mergensort_sol3(char* str1, char* str2, int len) {

	// there's probably a better way to go about this but this suffices

	int ascii_histogram[128] = { 0 }; // a histogram representing all the ascii appearances in the two strings
	int dest_counter = 0;

	for (int i = 0; i < 128; i++) {

		for (int j = 0; j < strlen(str1); j++) { // loop through each char in str1

			if (str1[j] == i)
				ascii_histogram[i]++; // add to the histogram if a character is present
		}
		for (int j = 0; j < strlen(str2); j++) { // loop through each char in str2

			if (str2[j] == i)
				ascii_histogram[i]++; // add to the histogram if a character is present
		}
	}

	for (int i = 0; i < 128; i++) { // this loops through our histogram and inserts the amount of characters present into the destination string

		for (int j = 0; j < ascii_histogram[i] && dest_counter < len; j++) {

			str1[dest_counter] = i;
			dest_counter++;
		}
	}

	str1[dest_counter] = '\0'; // insert null character at the end	
}

#pragma endregion
