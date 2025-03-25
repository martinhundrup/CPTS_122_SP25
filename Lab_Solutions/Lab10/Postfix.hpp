/*
 * File: Postfix.hpp
 * Author: Martin Hundrup
 * Professor: Andy O'Fallon
 * Class: CPT_S 122, Spring 2025
 * Assignment: Lab 10
 * Created: March 21, 2025
 */

#pragma once

#include <sstream>
#include "Stack.hpp"

using std::stringstream;

class Postfix {

private:

public:

	Postfix() = delete; // static class

	// evaluates a postfix string and returns the results
	static int solve(string expression);

	// converts an infix string to postfix and returns it
	static string convert(string expression);
};

int Postfix::solve(string expression) {

	int val = -INFINITY; // err val

	// convert to a string stream
	stringstream sstream = stringstream(expression);
	char next;
	Stack<int> stack;

	while (sstream >> next) { // parses using spaces

		switch (next) {
		case '=':
			if (stack.isEmpty()) return -INFINITY; // err
			else if (stack.size() > 1) return -INFINITY; // err
			else {
				if (stack.pop(val)) {
					return val;
				}
				else {
					return -INFINITY; // err
				}
			}
			break;
		case '*':
			if (stack.isEmpty() || stack.size() < 2) return -INFINITY; // err
			else {
				int v1 = 0, v2 = 0;
				if (!stack.pop(v2) || !stack.pop(v1)) return -INFINITY; // err
				int v3 = v1 * v2;
				if (!stack.push(v3)) return -INFINITY; // err
			}
			break;
		case '+':
			if (stack.isEmpty() || stack.size() < 2) return -INFINITY; // err
			else {
				int v1 = 0, v2 = 0;
				if (!stack.pop(v2) || !stack.pop(v1)) return -INFINITY; // err
				int v3 = v1 + v2;
				if (!stack.push(v3)) return -INFINITY; // err
			}
			break;
		case '-':
			if (stack.isEmpty() || stack.size() < 2) return -INFINITY; // err
			else {
				int v1 = 0, v2 = 0;
				if (!stack.pop(v2) || !stack.pop(v1)) return -INFINITY; // err
				int v3 = v1 - v2;
				if (!stack.push(v3)) return -INFINITY; // err
			}
			break;
		case '/':
			if (stack.isEmpty() || stack.size() < 2) return -INFINITY; // err
			else {
				int v1 = 0, v2 = 0;
				if (!stack.pop(v2) || !stack.pop(v1)) return -INFINITY; // err
				int v3 = v1 / v2;
				if (!stack.push(v3)) return -INFINITY; // err
			}
			break;
		default:
			int digit = next - '0';
			if (digit < 10 && digit > -1) {
				// valid
				if (!stack.push(digit)) return -INFINITY; // err
			}
			else return -INFINITY; // err
			break;
		}
	}

	return val;
}

string Postfix::convert(string expression) {

	// convert to a string stream
	stringstream sstream = stringstream(expression);
	char next;
	Stack<char> stack;

	stringstream postfix;

	while (sstream >> next) { // parses using spaces

		switch (next) {
		case '+':
		case '-': // lower precedence

			// case 1: empty stack
			if (stack.isEmpty()) {
				if (!stack.push(next)) return "NULL"; // err
				break;
			}
			else { // case 2: something(s) in stack
				char top = 0;
				while (1) {
					if (stack.isEmpty()) { // push next and exit loop
						if (!stack.push(next)) return "NULL"; // err
						break;
					}
					if (!stack.peek(top)) return "NULL"; // err
					if (top == '+' || top == '-' || top == '*' || top == '/') {
						if (!stack.pop(top)) return "NULL"; // time to pop
						postfix << top << ' '; // append a space
					}
					else {
						if (!stack.push(next)) return "NULL"; // err
						break;
					}
				}
			}
			break;
		case '*':
		case '/': // higher precedence
			// case 1: empty stack
			if (stack.isEmpty()) {
				if (!stack.push(next)) return "NULL"; // err
				break;
			}
			else { // case 2: something(s) in stack
				char top = 0;
				while (1) {
					if (stack.isEmpty()) { // push next and exit loop
						if (!stack.push(next)) return "NULL"; // err
						break;
					}
					if (!stack.peek(top)) return "NULL"; // err
					if (top == '*' || top == '/') {
						if (!stack.pop(top)) return "NULL"; // time to pop
						postfix << top << ' '; // append a space
					}
					else {
						if (!stack.push(next)) return "NULL"; // err
						break;
					}
				}
			}
			break;
		case '(':
			if (!stack.push(next)) return "NULL"; // err
			break;
		case ')':
			// case 1: empty stack
			if (stack.isEmpty()) {
				if (!stack.push(next)) return "NULL"; // err
				break;
			}
			else { // case 2: something(s) in stack
				char top = 0;
				while (1) {
					if (stack.isEmpty()) { // push next and exit loop
						if (!stack.push(next)) return "NULL"; // err
						break;
					}
					if (!stack.peek(top)) return "NULL"; // err
					if (top == '+' || top == '-' || top == '*' || top == '/') {
						if (!stack.pop(top)) return "NULL"; // time to pop
						postfix << top << ' '; // append a space
					}
					else if (top == '(') {
						// remove the left paren
						if (!stack.pop(top)) return "NULL";
						break;
					}
				}
			}
			break;
		default: // digits/vars
			postfix << next << ' '; // append a space
			break;
		}
	}

	// append the rest of the operators
		// case 1: empty stack
	if (stack.isEmpty()) {
		postfix << "= "; // append =
		return postfix.str();
	}
	else { // case 2: something(s) in stack
		char top = 0;
		while (1) {
			if (stack.isEmpty()) { // push next and exit loop
				postfix << "= "; // append =
				return postfix.str(); // done!
			}
			if (!stack.pop(top)) return "NULL"; // err
			postfix << top << ' '; // append a space
		}
	}
	postfix << "= "; // append =
	return postfix.str();
}