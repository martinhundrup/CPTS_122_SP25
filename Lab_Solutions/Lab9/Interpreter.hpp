/*
 * File: Interpreter.hpp
 * Author: Martin Hundrup
 * Professor: Andy O'Fallon
 * Class: CPT_S 122, Spring 2025
 * Assignment: Lab 9
 * Created: March 18, 2025
 */

#pragma once

#include <random>
#include <vector>
#include <string>
#include <sstream>
#include <iostream>
#include "BST.hpp"

class Interpreter {

private:

	// used to get input from the user
	static std::string prompt();

	// tokenizes the user's input
	static std::vector<std::string> tokenize(const std::string& str);

public:

	// static class - don't allow instances to be created
	Interpreter() = delete;

	// runs the interpreter
	static void run();
};

std::string Interpreter::prompt() {

	std::cout << "BST> ";

	std::string response;
	std::getline(std::cin, response);
	return response;
}

std::vector<std::string> Interpreter::tokenize(const std::string& str) {
	std::vector<std::string> tokens;
	std::istringstream iss(str);
	std::string token;
	while (iss >> token) {  // >> operator skips any whitespace
		tokens.push_back(token);
	}
	return tokens;
}

void Interpreter::run() {

	BST<int> bst = BST<int>();

	while (1) {

		std::string input;

		input = prompt();
		std::vector<std::string> tokens = tokenize(input);

		if (tokens.at(0) == "insert") {

			bst.insert(std::stoi(tokens.at(1)));
		}
		else if (tokens.at(0) == "delete") {

			bst.deleteData(std::stoi(tokens.at(1)));
		}
		else if (tokens.at(0) == "clear") {

			bst.clear();
		}
		else if (tokens.at(0) == "print") {

			bst.printInOrder();
		}
		else if (tokens.at(0) == "exit" || tokens.at(0) == "quit") {

			return;
		}
		else if (tokens.at(0) == "cls") {
			system("cls");
		}
		else {
			std::cout << "error" << std::endl;
		}
	}
}