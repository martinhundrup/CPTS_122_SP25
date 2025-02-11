/*
 * File: Complex.cpp
 * Author: Martin Hundrup
 * Professor: Andy O'Fallon
 * Class: CPT_S 122, Spring 2025
 * Assignment: Lab 5
 * Created: February 7, 2025
 */

#include "Complex.hpp"

#pragma region Constructors

Complex::Complex() {

	realPart = imaginaryPart = 0.0;
}

Complex::Complex(double _real, double _imaginary) {

	realPart = _real;
	imaginaryPart = _imaginary;
}

#pragma endregion

#pragma region Getters and Setters

double Complex::getRealPart() const {
	return realPart;
}

double Complex::getImaginaryPart() const {
	return imaginaryPart;
}

void Complex::setRealPart(double _real) {
	realPart = _real;
}

void Complex::setImaginaryPart(double _imaginary) {
	imaginaryPart = _imaginary;
}

#pragma endregion

#pragma region Operations

Complex& Complex::add(const Complex& rhs) {

	realPart += rhs.realPart;
	imaginaryPart += rhs.imaginaryPart;

	return *this;
}

void Complex::read() {

	char op = 0;
	std::cin >> realPart >> op >> imaginaryPart; // a + bi

	if (op == '-') imaginaryPart *= -1;
}

void Complex::print() const {

	std::cout << realPart << " + " << imaginaryPart << "i";
}

#pragma endregion

Complex add(const Complex& lhs, const Complex& rhs) {

	return Complex(lhs.getRealPart() + rhs.getRealPart(),
		lhs.getImaginaryPart() + rhs.getImaginaryPart());
}

Complex operator+ (const Complex& lhs, const Complex& rhs) {

	return add(lhs, rhs);
}

Complex operator- (const Complex& lhs, const Complex& rhs) {

	return Complex(lhs.getRealPart() - rhs.getRealPart(),
		lhs.getImaginaryPart() - rhs.getImaginaryPart());
}

std::istream& operator>> (std::istream& lhs, Complex& rhs) {

	char op = 0;
	double real = 0.0;
	double imaginary = 0.0;

	lhs >> real >> op >> imaginary; // a + bi

	rhs.setRealPart(real);

	if (op == '-') rhs.setImaginaryPart(imaginary * -1);
	else rhs.setImaginaryPart(imaginary);

	return lhs;
}

std::ostream& operator<< (std::ostream& rhs, const Complex& lhs) {

	std::cout << lhs.getRealPart() << " + " << lhs.getImaginaryPart() << "i";

	return rhs;
}