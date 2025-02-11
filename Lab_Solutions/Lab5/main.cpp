/*
 * File: main.cpp
 * Author: Martin Hundrup
 * Professor: Andy O'Fallon
 * Class: CPT_S 122, Spring 2025
 * Assignment: Lab 5
 * Created: February 7, 2025
 */

#include "lab5.hpp"
#include "Complex.hpp"

int main() {

	Complex c = Complex();
	Complex c1 = Complex(5.0, 6.0);

	std::cin >> c >> c1;
	std::cout << c << std::endl << c1 << std::endl;

	return 0;
}