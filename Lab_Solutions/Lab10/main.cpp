/*
 * File: main.cpp
 * Author: Martin Hundrup
 * Professor: Andy O'Fallon
 * Class: CPT_S 122, Spring 2025
 * Assignment: Lab 10
 * Created: March 21, 2025
 */

// This example illustrates how to define a Stack class template.

#include "TestStack.hpp"
#include "Postfix.hpp"

int main(void)
{
	string expression = "5 6 + 4 * 2 / ="; // expected: 22
	std::cout << Postfix::solve(expression) << std::endl;

	string infix1 = "A + B - C";
	string infix2 = "A + B * C";
	string infix3 = "( A + B ) / ( C - D )";
	string infix4 = "( ( A + B ) * ( C - D ) + E ) / ( F + G )";

	std::cout << Postfix::convert(infix1) << std::endl;
	std::cout << Postfix::convert(infix2) << std::endl;
	std::cout << Postfix::convert(infix3) << std::endl;
	std::cout << Postfix::convert(infix4) << std::endl;

	return 0;
}