/*
 * File: TestList.h
 * Author: Martin Hundrup
 * Professor: Andy O'Fallon
 * Class: CPT_S 122, Spring 2025
 * Assignment: Lab 2
 * Created: January 19, 2025
 */

#ifndef TESTLIST_H
#define TESTLISH_H

#define _CRT_SECURE_NO_WARNINGS

#include "lab2.h"

/*
	runs all tests and outputs their results

	@return nothing
*/
void runAllTests();

/*
	ensures the functionality of makeNode()

	@return success status
*/
Boolean testMakeNode();

/*
	ensures the functionality of insertContactInOrder()

	@return success status
*/
Boolean testInsertContactInOrder();

/*
	ensures the functionality of deleteContact()

	@return success status
*/
Boolean testDeleteContact();

/*
	ensures the functionality of editContact()

	@return success status
*/
Boolean testEditContact();

/*
	ensures the functionality of loadContacts()

	@return success status
*/
Boolean testLoadContacts();

/*
	ensures the functionality of storeContacts()

	@return success status
*/
Boolean testStoreContacts();

/*
	ensures the functionality of printList()

	@return success status
*/
Boolean testPrintList();

#endif