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

	Sorting::testSortFromCSV("large_arrays.csv", 100);
    
	//Interpreter::run();

	return 0;
}