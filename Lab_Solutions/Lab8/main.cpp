/*
 * File: main.cpp
 * Author: Martin Hundrup
 * Professor: Andy O'Fallon
 * Class: CPT_S 122, Spring 2025
 * Assignment: Lab 8
 * Created: March 1, 2025
 */

#include "Queue.hpp"

int main() {


	Queue<int> q;
	Queue<std::string> str_q;

	for (int i = 0; i < 10; i++) {

		q.enqueue(i);
		str_q.enqueue("hello");
	}

	q.printQueueRecursive();
	str_q.printQueueRecursive();

	while (!q.isEmpty()) {
		std::cout << q.dequeue() << std::endl;
		std::cout << str_q.dequeue() << std::endl;
	}

	return 0;
}