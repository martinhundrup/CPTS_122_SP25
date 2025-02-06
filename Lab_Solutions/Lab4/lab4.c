/*
 * File: lab4.c
 * Author: Martin Hundrup
 * Professor: Andy O'Fallon
 * Class: CPT_S 122, Spring 2025
 * Assignment: Lab 4
 * Created: February 2, 2025
 */

#include "lab4.h"

#pragma region Stack Operations

int isEmpty(Node* pTop) {

	return pTop == NULL;
}

int push(Node** pTop, double data) {

	// initialize new node
	Node* pNew = (Node*)malloc(sizeof(Node));
	if (!pNew) return 0; // failed
	pNew->data = data;

	// insert at front
	pNew->pNext = *pTop;
	*pTop = pNew;
	return 1; // success
}

double pop(Node** pTop) {

	if (isEmpty(*pTop)) return 0; // empty list

	// relink top of stack
	Node* pTemp = *pTop;
	*pTop = pTemp->pNext;

	// determine and return value
	double val = pTemp->data;
	free(pTemp); // don't forget this step!!
	return val;
}

double peek(Node* pTop) {

	if (isEmpty(pTop)) return 0; // empty list

	return pTop->data;
}

#pragma endregion