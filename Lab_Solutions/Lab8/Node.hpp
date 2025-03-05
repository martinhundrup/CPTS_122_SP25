/*
 * File: Node.hpp
 * Author: Martin Hundrup
 * Professor: Andy O'Fallon
 * Class: CPT_S 122, Spring 2025
 * Assignment: Lab 8
 * Created: March 1, 2025
 */

#pragma once

#include <iostream>

template<typename T> class Node {

private:

	T data; // the data stored in this node
	Node<T>* pNext; // pointer to the next node in order

public:

	// constructors
	Node(); // default constructor
	Node(T); // overloaded constructor

	// destructor - not needed, just for testing
	~Node();

	// getters
	Node<T>* getNext() const;
	T getData() const; // assumes shallow copy

	// setters
	void setNext(Node<T>*);
};

// constructors
template<typename T> Node<T>::Node() {

	data = T(); // default value of T
	pNext = nullptr;
}

template<typename T> Node<T>::Node(T _data) {

	data = _data; // assumes shallow copy
	pNext = nullptr;
}

template<typename T> Node<T>::~Node() {

	//std::cout << "node deleted!" << std::endl;
}

// getters
template<typename T> Node<T>* Node<T>::getNext() const {

	return pNext;
}

template<typename T> T Node<T>::getData() const {

	return data;
}

// setters
template<typename T> void Node<T>::setNext(Node<T>* _pNew) {

	pNext = _pNew;
}