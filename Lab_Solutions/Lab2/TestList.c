/*
 * File: TestList.c
 * Author: Martin Hundrup
 * Professor: Andy O'Fallon
 * Class: CPT_S 122, Spring 2025
 * Assignment: Lab 2
 * Created: January 19, 2025
 */

#include "TestList.h"

void runAllTests() {

	printf("testing:\n");

	printf("make node test: ");
	if (testMakeNode() == TRUE)
		printf(GRN "TRUE\n" WHT);
	else
		printf(RED "FALSE\n" WHT);

	printf("insert contact in order test: ");
	if (testInsertContactInOrder() == TRUE)
		printf(GRN "TRUE\n" WHT);
	else
		printf(RED "FALSE\n" WHT);

	printf("delete contact test: ");
	if (testDeleteContact() == TRUE)
		printf(GRN "TRUE\n" WHT);
	else
		printf(RED "FALSE\n" WHT);

	printf("edit contact test: ");
	if (testEditContact() == TRUE)
		printf(GRN "TRUE\n" WHT);
	else
		printf(RED "FALSE\n" WHT);

	printf("load contacts test: ");
	if (testLoadContacts() == TRUE)
		printf(GRN "TRUE\n" WHT);
	else
		printf(RED "FALSE\n" WHT);

	printf("store contacts test: ");
	if (testStoreContacts() == TRUE)
		printf(GRN "TRUE\n" WHT);
	else
		printf(RED "FALSE\n" WHT);

	printf("print list test: ");
	if (testPrintList() == TRUE)
		printf(GRN "TRUE\n" WHT);
	else
		printf(RED "FALSE\n" WHT);
}

Boolean testMakeNode() {

	// create contact to test against
	Contact testContact = { "test", "01234567890", "test@gmail.com", "testing function"};
	
	Node* pNode = makeNode(testContact); // a node* that stores the result of makeNode()

	if (strcmp(pNode->data.name, testContact.name) == 0 && strcmp(pNode->data.phone, testContact.phone) == 0 &&
		strcmp(pNode->data.email, testContact.email) == 0 && strcmp(pNode->data.title, testContact.title) == 0) {

		return TRUE; // all values are equal
	}

	return FALSE;
}

Boolean testInsertContactInOrder() {

	// create a contact for the back of the list
	Contact front = { "test a", "a01234567890", "testa@gmail.com", "atesting function" };

	// create contact for the front of the list
	Contact back = { "test c", "c01234567890", "testc@gmail.com", "ctesting function" };

	// create contact for initial insertion
	Contact middle = { "test b", "b01234567890", "testb@gmail.com", "btesting function" };

	Node* pList = NULL; // the testing linked list

	if (!insertContactInOrder(&pList, middle)) {
		return FALSE; // the insertion failed
	}

	if (!insertContactInOrder(&pList, front)) {
		return FALSE; // the insertion failed
	}

	if (!insertContactInOrder(&pList, back)) {
		return FALSE; // the insertion failed
	}

	// test the values of front
	if (strcmp(pList->data.name, front.name) != 0 || strcmp(pList->data.phone, front.phone) != 0 ||
		strcmp(pList->data.email, front.email) != 0 || strcmp(pList->data.title, front.title) != 0) {

		return FALSE; // at least one value wasn't equal
	}
	
	Node* pNext = pList->pNext;
	if (pNext == NULL) {
		return FALSE; // returns false if the list was not linked properly
	}

	// test the values of middle
	if (strcmp(pNext->data.name, middle.name) != 0 || strcmp(pNext->data.phone, middle.phone) != 0 ||
		strcmp(pNext->data.email, middle.email) != 0 || strcmp(pNext->data.title, middle.title) != 0) {

		return FALSE; // at least one value wasn't equal
	}

	pNext = pNext->pNext;
	if (pNext == NULL) {
		return FALSE; // returns false if the list was not linked properly
	}

	// test the values of back
	if (strcmp(pNext->data.name, back.name) != 0 || strcmp(pNext->data.phone, back.phone) != 0 ||
		strcmp(pNext->data.email, back.email) != 0 || strcmp(pNext->data.title, back.title) != 0) {

		return FALSE; // at least one value wasn't equal
	}

	return TRUE; // if we get here, we passed all the tests and can pass the overall test
}

Boolean testDeleteContact() {


	// create a contact for the back of the list
	Contact front = { "test a", "a01234567890", "testa@gmail.com", "atesting function" };

	// create contact for the front of the list
	Contact back = { "test c", "c01234567890", "testc@gmail.com", "ctesting function" };

	// create contact for initial insertion
	Contact middle = { "test b", "b01234567890", "testb@gmail.com", "btesting function" };

	Node* pList = NULL; // the testing linked list

	if (!insertContactInOrder(&pList, middle)) { // insert into front
		return FALSE; // the insertion failed
	}

	if (!deleteContact(&pList, middle)) { // attempt to delete the front node
		return FALSE; // the deletion at front failed
	}

	if (!insertContactInOrder(&pList, front)) { // insert into front
		return FALSE; // the insertion failed
	}

	if (deleteContact(&pList, back)) { // attempt to delete a node that doesn't exist
		return FALSE; // the insertion succeeded unexectedly
	}

	if (!insertContactInOrder(&pList, back)) { // insert into back
		return FALSE; // the insertion failed
	}

	if (!deleteContact(&pList, back)) { // attempt to delete at back
		return FALSE; // the deletion at back failed
	}

	// test the values of front
	if (strcmp(pList->data.name, front.name) != 0 || strcmp(pList->data.phone, front.phone) != 0 ||
		strcmp(pList->data.email, front.email) != 0 || strcmp(pList->data.title, front.title) != 0) {

		return FALSE; // at least one value wasn't equal
	}

	return TRUE; // if we get here, we passed all the tests and can pass the overall test
}

Boolean testEditContact() {

	// no implementation
	return FALSE;
}

Boolean testLoadContacts() {

	FILE* infile = fopen("testinfile.txt", "r"); // open the test input file for mode for reading

	Node* pList = NULL; // the testing linked list

	if (!loadContacts(infile, &pList)) {
		fclose(infile); // close infile
		return FALSE; // the load failed
	}

	fclose(infile); // close infile

	// create a contact for the back of the list
	Contact front = { "test a", "a0123456789", "testa@gmail.com", "atesting function" };

	// create contact for the front of the list
	Contact back = { "test c", "c0123456789", "testc@gmail.com", "ctesting function" };

	// create contact for initial insertion
	Contact middle = { "test b", "b0123456789", "testb@gmail.com", "btesting function" };

	// test the values of front
	if (strcmp(pList->data.name, front.name) != 0 || strcmp(pList->data.phone, front.phone) != 0 ||
		strcmp(pList->data.email, front.email) != 0 || strcmp(pList->data.title, front.title) != 0) {

		return FALSE; // at least one value wasn't equal
	}

	Node* pNext = pList->pNext;
	if (pNext == NULL) {
		return FALSE; // returns false if the list was not linked properly
	}

	// test the values of middle
	if (strcmp(pNext->data.name, middle.name) != 0 || strcmp(pNext->data.phone, middle.phone) != 0 ||
		strcmp(pNext->data.email, middle.email) != 0 || strcmp(pNext->data.title, middle.title) != 0) {

		return FALSE; // at least one value wasn't equal
	}

	pNext = pNext->pNext;
	if (pNext == NULL) {
		return FALSE; // returns false if the list was not linked properly
	}

	// test the values of back
	if (strcmp(pNext->data.name, back.name) != 0 || strcmp(pNext->data.phone, back.phone) != 0 ||
		strcmp(pNext->data.email, back.email) != 0 || strcmp(pNext->data.title, back.title) != 0) {

		return FALSE; // at least one value wasn't equal
	}

	return TRUE; // if we get here, we passed all the tests and can pass the overall test

}

Boolean testStoreContacts() {

	// create a contact for the back of the list
	Contact front = { "test a", "0123456789", "testa@gmail.com", "atesting function" };

	// create contact for the front of the list
	Contact back = { "test c", "0123456789", "testc@gmail.com", "ctesting function" };

	// create contact for initial insertion
	Contact middle = { "test b", "0123456789", "testb@gmail.com", "btesting function" };

	Node* pList = NULL; // the testing linked list

	if (!insertContactInOrder(&pList, middle)) {
		return FALSE; // the insertion failed
	}

	if (!insertContactInOrder(&pList, front)) {
		return FALSE; // the insertion failed
	}

	if (!insertContactInOrder(&pList, back)) {
		return FALSE; // the insertion failed
	}

	FILE* outfile = fopen("testoutfile.txt", "w"); // open the test output file for mode for writing

	if (!storeContacts(outfile, pList)) {
		fclose(outfile);
		return FALSE; // store failed
	}

	// close outfile and open for mode read
	fclose(outfile);
	outfile = fopen("testoutfile.txt", "r");

	char temp[200]; // holds the lines of the file

	// check first line
	fgets(temp, 199, outfile);
	remove_char(temp, '\n');
	if (strcmp(temp, "test a,0123456789,testa@gmail.com,atesting function") != 0) {
		return FALSE; // store unsuccessfull
	}

	// check first line
	fgets(temp, 199, outfile);
	remove_char(temp, '\n');
	if (strcmp(temp, "test b,0123456789,testb@gmail.com,btesting function") != 0) {
		return FALSE; // store unsuccessfull
	}

	// check first line
	fgets(temp, 199, outfile);
	remove_char(temp, '\n');
	if (strcmp(temp, "test c,0123456789,testc@gmail.com,ctesting function") != 0) {
		return FALSE; // store unsuccessfull
	}
	

	fclose(outfile);

	return TRUE; // if we get here, we passed all the tests and can pass the overall test
}

Boolean testPrintList() {

	// no implementation
	return FALSE;
}