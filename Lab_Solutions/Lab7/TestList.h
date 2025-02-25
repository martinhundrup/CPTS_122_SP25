#pragma once

#include "List.h"

class TestList {

public:

	List* initializeList();

	bool testInsertInOrder();
	bool testInsertAtEnd();
	bool testInsertAtFront();
	bool testDeleteNode();
	bool testDeleteAtFront();
	bool testDeleteAtEnd();
	bool testIsEmpty();
	bool testCopyConstructor();
	bool testAssignmentOperator();

	bool runTests();
};
