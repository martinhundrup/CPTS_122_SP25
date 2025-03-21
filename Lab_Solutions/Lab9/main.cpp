/*
 * File: main.cpp
 * Author: Martin Hundrup
 * Professor: Andy O'Fallon
 * Class: CPT_S 122, Spring 2025
 * Assignment: Lab 9
 * Created: March 7, 2025
 */

#include "Interpreter.hpp"
#include "BST.hpp"

int main() {

	// --- Interpreter for real-time interaction -- //
	Interpreter::run(); // type 'quit' to exit

	// --- Scripted Testing --- //+263

	BST<int> bst;

	bst.insert(42);
	bst.insert(25);
	bst.insert(75);
	bst.insert(10);
	bst.insert(30);
	bst.insert(65);
	bst.insert(100);
	bst.insert(15);
	bst.insert(70);

	bst.printInOrder();
	bst.printPreOrder();
	bst.printPostOrder();

	// --- Random Testing --- //

	std::srand(std::time(0)); // start random number generation using seed now

	bst.clear(); // clear for new use

	for (int i = 0; i < 100; i++) {

		bst.insert(rand() % 101); // insert random number [0, 100]
	}

	bst.printInOrder();
	bst.clear();
	bst.printInOrder();

	return 0;
}