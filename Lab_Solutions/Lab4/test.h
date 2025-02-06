/*
 * File: test.h
 * Author: Martin Hundrup
 * Professor: Andy O'Fallon
 * Class: CPT_S 122, Spring 2025
 * Assignment: Lab 4
 * Created: February 2, 2025
 */

// guard code
#ifndef TEST_H
#define TEST_H

#include "lab4.h"

/*
	Performs all tests and prints results to the screen
*/
void test_all();

/*
	Determines the success of isEmpty()
*/
int test_isEmpty();

/*
	Determins the success of push()
*/
int test_push();

/*
	Determines the success of pop()
*/
int test_pop();

/*
	Determines the success of peek()
*/
int test_peek();

#endif
