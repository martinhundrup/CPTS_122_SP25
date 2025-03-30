/*
 * File: BST.hpp
 * Author: Martin Hundrup
 * Professor: Andy O'Fallon
 * Class: CPT_S 122, Spring 2025
 * Assignment: Lab 9
 * Created: March 7, 2025
 */

#pragma once

#include <iostream>

template<typename T>
class BST {

private:

	// node definition
	// nothing outside the BST should have access to it
	class Node {

	public: 

		// why are these OK to be public?
		T data;
		int count; // we're going to count repeat data
		Node* pLeft;
		Node* pRight;

		Node(); // default constructor
		Node(T); // overloaded constructor

		// stream insertion for node
		friend std::ostream& operator<<(std::ostream& lhs, const Node& rhs) {
			lhs << rhs.data;
			return lhs;
		}
	};

	// pointer to the root of the tree
	Node* pRoot;

	// --- Methods --- //

	// recursive helper function for inserting into the tree
	void insert(Node** pCur, T data);

	// recursive helper function overload for printing the tree in-order
	void printInOrder(Node* pCur);

	// recursive helper function overload for printing the tree pre-order
	void printPreOrder(Node* pCur);

	// recursive helper function overload for printing the tree post-order
	void printPostOrder(Node* pCur);

	// deletes all nodes in the tree recusively
	void deleteTree(Node* pCur);

	// deletes a node in the tree - lazy delete
	void deleteNode(Node* pCur, T data);

public:

	// basic/default constructor
	BST();

	// destructor - necessary for dynamic memory
	~BST();
	
	// --- Methods --- //

	// public interface for inserting into the tree
	void insert(T data);

	// public interface for printing the tree in-order
	void printInOrder();
	
	// public interface for printing the tree pre-order
	void printPreOrder();

	// public interface for printing the tree post-order
	void printPostOrder();

	// determines if the tree is empty or not
	bool isEmpty();

	// deletes all node in the tree - clears it
	void clear();

	// public interface for lazy delete
	void deleteNode(T data);
};

#pragma region Node Methods

template<typename T>
BST<T>::Node::Node() {

	data = T();
	pLeft = pRight = nullptr;
	count = 1; // if we are creating a node with data, we have at least 1
}

template<typename T>
BST<T>::Node::Node(T _data) {

	data = _data;
	pLeft = pRight = nullptr;
	count = 1; // if we are creating a node with data, we have at least 1
}

#pragma endregion


#pragma region Private Methods

template<typename T>
void BST<T>::insert(Node** pCur, T data) {

	if (*pCur == nullptr) {
		*pCur = new Node(data);
		return;
	}

	else if ((*pCur)->count <= 0) { // check if we can re-use this node

		if (((*pCur)->pLeft == nullptr || (*pCur)->pLeft->data < data) &&
			((*pCur)->pRight == nullptr || (*pCur)->pRight->data > data)) { // we can place here

			(*pCur)->data = data;
			(*pCur)->count++;
			return;
		}
	}

	if (data < (*pCur)->data)
		insert(&(*pCur)->pLeft, data); // insert left

	else if (data > (*pCur)->data) 
		insert(&(*pCur)->pRight, data); // insert left

	else 
		(*pCur)->count++; // equivalent data - increase count
}

template<typename T>
void BST<T>::printInOrder(Node* pCur) {

	if (!pCur) return; // base case
	printInOrder(pCur->pLeft); // recurse left
	
	for (int i = 0; i < pCur->count; i++) // print current
		std::cout << *pCur << " ";

	printInOrder(pCur->pRight); // recurse right
}

template<typename T>
void BST<T>::printPreOrder(Node* pCur) {

	if (!pCur) return; // base case

	for (int i = 0; i < pCur->count; i++) // print current
		std::cout << *pCur << " ";

	printPreOrder(pCur->pLeft); // recurse left
	printPreOrder(pCur->pRight); // recurse right
}

template<typename T>
void BST<T>::printPostOrder(Node* pCur) {

	if (!pCur) return; // base case

	printPostOrder(pCur->pLeft); // recurse left
	printPostOrder(pCur->pRight); // recurse right

	for (int i = 0; i < pCur->count; i++) // print current
		std::cout << *pCur << " ";
}

template<typename T>
void BST<T>::deleteTree(Node* pCur) {

	if (!pCur) return; // base case

	deleteTree(pCur->pLeft); // recurse left
	deleteTree(pCur->pRight); // recurse right

	delete pCur; // delete this
}

template<typename T>
void BST<T>::deleteNode(Node* pCur, T data) {

	if (!pCur) return; // base case

	if (pCur->data == data && pCur->count > 0) { // we found it and have it
		pCur->count--; return;
	}
	
	deleteData(pCur->pLeft, data); // recurse left
	deleteData(pCur->pRight, data); // recurse right
}

#pragma endregion


#pragma region Public Methods

template<typename T>
BST<T>::BST() {

	pRoot = nullptr;
}

template<typename T>
BST<T>::~BST() {

	clear();
}

template<typename T>
void BST<T>::insert(T data) {

	insert(&pRoot, data);
}

template<typename T>
void BST<T>::printInOrder() {

	printInOrder(pRoot);
	std::cout << std::endl;
}

template<typename T>
void BST<T>::printPreOrder() {

	printPreOrder(pRoot);
	std::cout << std::endl;
}

template<typename T>
void BST<T>::printPostOrder() {

	printPostOrder(pRoot);
	std::cout << std::endl;
}

template<typename T>
bool BST<T>::isEmpty() {

	return false;
}

template<typename T>
void BST<T>::clear() {

	deleteTree(pRoot);
	pRoot = nullptr;
}

template<typename T>
void BST<T>::deleteNode(T data) {

	deleteData(pRoot, data);
}

#pragma endregion