#pragma once

#include <iostream>

template <typename T>
class Node {

private:

	Node<T>* pLeft;
	Node<T>* pRight;

	T data;

public:


	Node() {
		pLeft = pRight = nullptr;
		data = T();
	}

	Node(T _t) {
		pLeft = pRight = nullptr;
		data = _t;
	}

	// getters
	Node<T>* getLeft() { return pLeft; }
	Node<T>* getRight() { return pRight; }
	T getData() { return data; }

	void setLeft(Node<T>* l) { pLeft = l; }
	void setRight(Node<T>* r) { pRight = r; }
	void setData(T _t) { data = _t; }
};