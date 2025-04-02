/*
 * File: main.cpp
 * Author: Martin Hundrup
 * Professor: Andy O'Fallon
 * Class: CPT_S 122, Spring 2025
 * Assignment: Lab 11
 * Created: March 29, 2025
 */

#include "Interpreter.hpp"
#include "Sorting.hpp"

int main() {

	// uncomment to test your merge sort function!
	Sorting::testSortFromCSV("large_arrays.csv", 100000);

	// uncomment to play around with your BST!
	Interpreter::run();

	return 0;
}