/*
 * File: Complex.hpp
 * Author: Martin Hundrup
 * Professor: Andy O'Fallon
 * Class: CPT_S 122, Spring 2025
 * Assignment: Lab 5
 * Created: February 7, 2025
 */

#pragma once

#include "lab5.hpp"

class Complex {

private:

	double realPart;
	double imaginaryPart;

public:

#pragma region Constructors

	/*
		Default constructor - initializes members to default values
	*/
	Complex();

	/*
		Overloaded constructor

		@param the real part
		@param the imaginary part
	*/
	Complex(double, double);

#pragma endregion


#pragma region Getters and Setters

	/*
		Gets the real part
		@return the real part
	*/
	double getRealPart() const;

	/*
		Gets the imaginary part
		@return the imaginary part
	*/
	double getImaginaryPart() const;

	/*
		Sets the real part
		@param the new real part
	*/
	void setRealPart(double);

	/*
		Sets the imaginary part
		@param the new imaginary part
	*/
	void setImaginaryPart(double);

#pragma endregion

#pragma region Operations

	/*
		Adds another Complex to this one
		@param a reference to another Complex
		@return a reference to this Complex
	*/
	Complex& add(const Complex&);

	/*
		Reads and stores input from the terminal in the form a + bi
	*/
	void read();

	/*
		Prints the contents of the object into the output stream in the form a + bi
	*/
	void print() const;

#pragma endregion


};

/*
	Adds two Complex objects together and returns the result
	@param a reference to the left hand side Complex
	@param a reference to the right hand side Complex
	@return a copy of the newly created Complex result
*/
Complex add(const Complex&, const Complex&);

/*
	Addition operator overload for adding two Complex objects
	@param a reference to the left hand side Complex
	@param a reference to the right hand side Complex
	@return a copy of the newly created Complex result 
*/
Complex operator+ (const Complex&, const Complex&);

/*
	Subtraction operator overload for adding two Complex objects
	@param a reference to the left hand side Complex
	@param a reference to the right hand side Complex
	@return a copy of the newly created Complex result
*/
Complex operator- (const Complex&, const Complex&);

/*
	Stream extraction operator overload
	@param the input stream
	@param the Complex to read and store into
	@return the rest of the input stream
*/
std::istream& operator>> (std::istream&, Complex&);

/*
	Stream insertion operator overload
	@param the output stream
	@param the Complex to read from
	@return the remaining output stream
*/
std::ostream& operator<< (std::ostream&, const Complex&);