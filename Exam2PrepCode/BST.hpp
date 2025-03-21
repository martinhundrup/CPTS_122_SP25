#pragma once

#include "Node.hpp"

template <typename T>
class BST {

private:

	Node<T>* pRoot;
	Node<T>* insert(Node<T>* pCur, T newData);
	void printInOrder(Node<T>* pCur);
	void destroy(Node<T>* pCur);

public:

	BST() { pRoot = nullptr; }
	~BST() { std::cout << "tree destructor" << std::endl; }
	void insert(T newData);
	void printInOrder();

	void destroy();

};

template <typename T>
void BST<T>::insert(T newData) {

	pRoot = insert(pRoot, newData);
}

template <typename T>
Node<T>* BST<T>::insert(Node<T>* pCur, T newData) {

	if (pCur == nullptr) {
		return new Node<T>(newData);
	}
	else if (newData < pCur->getData()) { // insert left
	
		pCur->setLeft(insert(pCur->getLeft(), newData));
	}
	else if (newData > pCur->getData()) { // insert right

		pCur->setRight(insert(pCur->getRight(), newData));
	}
	return pCur;
}

template<typename T>
void BST<T>::printInOrder(Node<T>* pCur)
{
	if (pCur == nullptr) {
		return;
	}

	printInOrder(pCur->getLeft());
	std::cout << pCur->getData() << " ";
	printInOrder(pCur->getRight());
}



template<typename T>
void BST<T>::printInOrder()
{
	printInOrder(pRoot);
}


template <typename T>
void BST<T>::destroy() {
	destroy(pRoot);
	pRoot = nullptr;
}

template <typename T>
void BST<T>::destroy(Node<T>* pCur) {
	
	if (pCur == nullptr) return;
	destroy(pCur->getLeft());
	destroy(pCur->getRight());
	delete pCur;
}