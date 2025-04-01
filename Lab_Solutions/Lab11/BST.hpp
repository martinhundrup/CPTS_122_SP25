/*
 * File: BST.hpp
 * Author: Martin Hundrup
 * Professor: Andy O'Fallon
 * Class: CPT_S 122, Spring 2025
 * Assignment: Lab 11
 * Created: March 29, 2025
 */

#pragma once

#include <iostream>

// this uses tree rotation deletion - for lazy delete see lab 9
template<typename T>
class BST {

private:

	// node definition
	// nothing outside the BST should have access to it
	class Node {

	public:

		// why are these OK to be public?
		T data;
		Node* pLeft;
		Node* pRight;

		Node(); // default constructor
		Node(T); // overloaded constructor

		bool isLeaf() { 
			return pLeft == nullptr && pRight == nullptr; 
		}

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
	void deleteNode(Node*& pCur, T data);

	// finds the right successor of a node
	Node*& getRightSuccessor(Node*& pStart);

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

	// public interface for delete
	void deleteNode(T data);
};

#pragma region Node Methods

template<typename T>
BST<T>::Node::Node() {

	data = T();
	pLeft = pRight = nullptr;
}

template<typename T>
BST<T>::Node::Node(T _data) {

	data = _data;
	pLeft = pRight = nullptr;
}

#pragma endregion


#pragma region Private Methods

template<typename T>
void BST<T>::insert(Node** pCur, T data) {

	if (*pCur == nullptr)
		*pCur = new Node(data);

	else if (data < (*pCur)->data)
		insert(&(*pCur)->pLeft, data); // insert left

	else if (data > (*pCur)->data)
		insert(&(*pCur)->pRight, data); // insert left
}

template<typename T>
void BST<T>::printInOrder(Node* pCur) {

	if (!pCur) return; // base case

	printInOrder(pCur->pLeft); // recurse left
	std::cout << *pCur << " ";
	printInOrder(pCur->pRight); // recurse right
}

template<typename T>
void BST<T>::printPreOrder(Node* pCur) {

	if (!pCur) return; // base case

	std::cout << *pCur << " ";
	printPreOrder(pCur->pLeft); // recurse left
	printPreOrder(pCur->pRight); // recurse right
}

template<typename T>
void BST<T>::printPostOrder(Node* pCur) {

	if (!pCur) return; // base case

	printPostOrder(pCur->pLeft); // recurse left
	printPostOrder(pCur->pRight); // recurse right
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
void BST<T>::deleteNode(Node*& pCur, T data) {

	if (!pCur) return; // base case, didn't find the node

	if (pCur->data > data) deleteNode(pCur->pLeft, data); // recurse left
	else if (pCur->data < data) deleteNode(pCur->pRight, data); // recurse right
	else { // we're deleting pCur

		// case 1: pCur is a leaf
		if (pCur->isLeaf()) {
			delete pCur;
			pCur = nullptr;
		}
		else if (pCur->pLeft == nullptr) { // case 2: no left node

			Node* pNode = pCur->pRight;
			delete pCur;
			pCur = pNode;
			return;
		}
		else if (pCur->pRight == nullptr) { // case 2.5: no right node

			Node* pNode = pCur->pLeft;
			delete pCur;
			pCur = pNode;
			return;
		}
		else { // case 3: find successor

			// steps:
			// 1. find successor
			// 2. swap the data (not the node!) between the successor and this
			// 3. perform case 2/2.5 delete on the successor node

			// 1. find successor
			Node*& successor = getRightSuccessor(pCur->pRight);

			// 2. swap the data (not the node!) between the successor and this
			T tempData = pCur->data;
			pCur->data = successor->data;
			successor->data = tempData;

			// 3. perform case 2/2.5 delete on the successor node
			return deleteNode(successor, data);
		}
	}
}

template <typename T>
typename BST<T>::Node*& BST<T>::getRightSuccessor(Node*& pStart) {

	if (pStart->pLeft == nullptr) return pStart;
	else return getRightSuccessor(pStart->pLeft);
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

	deleteNode(pRoot, data);
}

#pragma endregion