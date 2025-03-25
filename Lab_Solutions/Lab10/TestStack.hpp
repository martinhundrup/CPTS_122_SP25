/*
 * File: TestStack.hpp
 * Author: Martin Hundrup
 * Professor: Andy O'Fallon
 * Class: CPT_S 122, Spring 2025
 * Assignment: Lab 10
 * Created: March 21, 2025
 */

#pragma once

#include "Stack.hpp"

template <class T>
class TestStack
{
public:
	TestStack();
	~TestStack();
	void Test();

private:
	Stack<T> theStack;
};

template <class T>
TestStack<T>::TestStack() : theStack(0) // this is initializing the newSize of the stack object to 0
{
	// intentionally left empty
}

template <class T>
TestStack<T>::~TestStack()
{
	// intentionally left empty
}

template <class T>
void TestStack<T>::Test()
{
	int x = 1, y = 2, z = 3;

	theStack.push(x);
	theStack.push(y);
	theStack.push(z);

	while (!theStack.isEmpty()) {

		int t = 0;
		if (theStack.pop(t)) {
			std::cout << t << std::endl;
		}
		else {
			std::cout << "failed to pop" << std::endl;
		}
	}
}
