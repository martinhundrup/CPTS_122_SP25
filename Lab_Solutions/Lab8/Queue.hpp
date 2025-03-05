/*
 * File: Queue.hpp
 * Author: Martin Hundrup
 * Professor: Andy O'Fallon
 * Class: CPT_S 122, Spring 2025
 * Assignment: Lab 8
 * Created: March 1, 2025
 */

#pragma once

#include <iostream>
#include "Node.hpp"

template<typename T> class Queue {

private:

	Node<T>* pHead; // head ptr
	Node<T>* pTail; // tail ptr

	void printQueueReursiveHelper(Node<T>*);

public:

	// constructors
	Queue(); // default constructor

	// destructors
	~Queue();

	// methods
	bool isEmpty(); // determines if the queue is empty or not
	bool enqueue(T); // inserts a new node into the end. returns success.
	T dequeue(); // returns data in the front and deletes the front. assumes shallow copy
	void printQueueRecursive(); // displays all values in the queue to the screen - uses recursion.
};

template<typename T> Queue<T>::Queue() {
	
	pHead = pTail = nullptr;
}

template<typename T> Queue<T>::~Queue() {

	// loop through queue and delete everything
	while (!isEmpty()) {
		dequeue();
	}
}

template<typename T> bool Queue<T>::isEmpty() {

	return pHead == nullptr;
}

template<typename T> bool Queue<T>::enqueue(T _data) {

	if (isEmpty()) {

		pHead = pTail = new Node<T>(_data);
		return true;
	}

	pTail->setNext(new Node<T>(_data));
	pTail = pTail->getNext();
	return true;
}

template<typename T> T Queue<T>::dequeue() {

	// IMPORTANT! this function assumes the list is not empty.
	// this will error if the queue is empty

	Node<T>* pOld = pHead;
	pHead = pOld->getNext();

	// check in case of 1 length queue
	if (pTail == pOld) {
		pHead = pTail = nullptr;
	}
	
	// return the data
	T data = pOld->getData();
	delete pOld;
	return data;
}

template<typename T> void Queue<T>::printQueueRecursive() {

	printQueueReursiveHelper(pHead);
}

template<typename T> void Queue<T>::printQueueReursiveHelper(Node<T>* pNode) {

	if (pNode == nullptr) return; // base case

	std::cout << pNode->getData() << std::endl;
	printQueueReursiveHelper(pNode->getNext());
}