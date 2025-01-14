/*
 * File: lab1.h
 * Author: Martin Hundrup
 * Professor: Andy O'Fallon
 * Class: CPT_S 122, Spring 2024
 * Assignment: Lab 1
 * Created: January 14, 2025
 */
 
// guard code
#ifndef LAB1_H
#define LAB1_H

// to use printf() and scanf()
#define CRT_SECURE_NO_WARNINGS

// library includes
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
 
// code organization
#pragma region Task 1

// one entry point function per task
void task_1();

#pragma endregion

#pragma region Task 2

/*
	performs example uses of the task 2 problems
*/
void task_2();

/*
	concatenates two strings

	@param the string to append onto
	@param the string to copy from

	@return the product - intended to be the same as the destination param
*/
char* my_strcat(char* destination, const char* source);

/*
	recursively reverses a string in place

	@param the string to reverse
*/
void recursive_string_reverse(char* str);

/*
	tokenizes a string

	@param the string to tokenize - make NULL to continue tokening the previous call's string
	@param the characters to use as delimeters
	
	@return a pointer to the beginning of the next token
*/
char* my_strtok(char* str, char* delims);

/*
	merges two unsorted strings - merges into a third, fixed size array

	@param the first string to merge
	@param the second string to merge
	@param the string to store the product string in
	@param the max amount of characters to merge
*/
void str_mergensort_so1l(char* str1, char* str2, char* dest, int len);

/*
	merges two unsorted strings - merges into a third, dynamically sized array

	@param the first string to merge
	@param the second string to merge
	
	@return a pointer to the heap-allocated product string
*/
char* str_mergensort_sol2(char* str1, char* str2);

/*
	merges two unsorted strings - merges into str 1

	@param the first string to merge
	@param the second string to merge
	@param the pointer to the product string - should be same as str1 param
*/
char* str_mergensort_sol3(char* str1, char* str2, int len);

#pragma endregion

#endif