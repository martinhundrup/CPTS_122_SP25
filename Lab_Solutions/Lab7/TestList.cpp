#include "TestList.h"

List* TestList::initializeList() {

	List* list = new List();
	list->insertAtEnd(1);
	list->insertAtEnd(3);
	list->insertAtEnd(5);
	return list;
}
bool TestList::testInsertInOrder() {

	List* list = initializeList();
	list->insertInOrder(2);

	ListNode* pTemp = list->getHeadPtr()->getNextPtr();
	return pTemp->getData() == 2;
}
bool TestList::testInsertAtEnd() {

	List* list = initializeList();
	list->insertAtEnd(7);

	ListNode* pTemp = list->getHeadPtr()->getNextPtr()->getNextPtr()->getNextPtr();
	return pTemp->getData() == 7;
}
bool TestList::testInsertAtFront() {

	List* list = initializeList();
	list->insertAtFront(0);

	return list->getHeadPtr()->getData() == 0;
}
bool TestList::testDeleteNode() {

	List* list = initializeList();
	list->deleteNode(3);

	return list->getHeadPtr()->getNextPtr()->getData() == 5;
}
bool TestList::testDeleteAtFront() {

	List* list = initializeList();
	return list->deleteAtFront() == 1;
}
bool TestList::testDeleteAtEnd() {
	
	List* list = initializeList();
	return list->deleteAtEnd() == 5;
}
bool TestList::testIsEmpty() {
	
	List* list = initializeList();
	return !list->isEmpty();
}
bool TestList::testCopyConstructor() {

	List* list1 = initializeList();
	List list2 = *list1;

	return list2.getHeadPtr()->getData() == list1->getHeadPtr()->getData()
		&& list2.getHeadPtr() != list1->getHeadPtr();
}
bool TestList::testAssignmentOperator() {

	List* list1 = initializeList();
	List list2;
	list2 = *list1;

	return list2.getHeadPtr()->getData() == list1->getHeadPtr()->getData()
		&& list2.getHeadPtr() != list1->getHeadPtr();
}
	 
bool TestList::runTests() {

	std::cout << "Result of testInsertInOrder(): " << testInsertInOrder() << std::endl;
	std::cout << "Result of testInsertAtFront(): " << testInsertAtFront() << std::endl;
	std::cout << "Result of testInsertAtBack(): " << testInsertAtEnd() << std::endl;
	std::cout << "Result of testDeleteNode(): " << testDeleteNode() << std::endl;
	std::cout << "Result of testDeleteAtFront(): " << testDeleteAtFront() << std::endl;
	std::cout << "Result of testDeleteAtEnd(): " << testDeleteAtEnd() << std::endl;
	std::cout << "Result of testIsEmpty(): " << testIsEmpty() << std::endl;
	std::cout << "Result of testCopyConstructor: " << testCopyConstructor() << std::endl;
	std::cout << "Result of testAssignmentOperator: " << testAssignmentOperator() << std::endl;
	return false;
}