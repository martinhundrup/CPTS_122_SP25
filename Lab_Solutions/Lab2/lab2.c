/*
 * File: lab2.c
 * Author: Martin Hundrup
 * Professor: Andy O'Fallon
 * Class: CPT_S 122, Spring 2025
 * Assignment: Lab 2
 * Created: January 19, 2025
 */

#include "lab2.h"

#pragma region Task 1

void task_1() {

	Node* pList = NULL;

	while (1) {

		system("cls");
		printMenu();

		printf("> ");
		int choice = get_int();

		if (choice == 1) { // load contacts

			FILE* infile = fopen("contacts.txt", "r");

			if (loadContacts(infile, &pList) == TRUE)
				printf("\ncontacts loaded succesfully!\n");
			else
				fprintf(stderr, "\nan error occurred while trying to load contacts.\n");

			fclose(infile);
		}
		else if (choice == 2) { // store contacts

			FILE* infile = fopen("contacts.txt", "w");

			if (storeContacts(infile, pList) == TRUE)
				printf("\ncontacts stored succesfully!\n");
			else
				fprintf(stderr, "\nan error occurred while trying to store contacts.\n");

			fclose(infile);
		}
		else if (choice == 3) { // display contacts

			printList(pList);
		}
		else if (choice == 4) { // add contact

			char buffer[200] = { 0 };
			Contact contact = { 0 };

#pragma region Create Name

			printf("enter the new name:\n");
			printf("> ");
			fgets(buffer, 99, stdin);
			strncpy(contact.name, buffer, 49);

#pragma endregion

#pragma region Create Phone

			printf("enter the new phone:\n");
			printf("> ");
			fgets(buffer, 99, stdin);
			strncpy(contact.phone, buffer, 11);

#pragma endregion

#pragma region Create Email

			printf("enter the new email:\n");
			printf("> ");
			fgets(buffer, 99, stdin);
			strncpy(contact.email, buffer, 49);

#pragma endregion

#pragma region Create Title

			printf("enter the new title:\n");
			printf("> ");
			fgets(buffer, 99, stdin);
			strncpy(contact.title, buffer, 19);

#pragma endregion

			if (insertContactInOrder(&pList, contact) == TRUE)
				printf("contact created and inserted succesfully!\n");
			else
				fprintf(stderr, "error when creating and/or inserting contact.\n");
		}
		else if (choice == 5) { // edit contact

			char buffer[200] = { 0 };
			Contact contact = { 0 };

			printf("enter the name to search for:\n");
			printf("> ");
			fgets(buffer, 99, stdin);
			remove_char(buffer, '\n');
			strncpy(contact.name, buffer, 49);

			if (editContact(pList, contact) == TRUE)
				printf("contact found and edited succesfully!\n");
			else
				fprintf(stderr, "error when finding and/or editing contact.\n");
		}
		else if (choice == 6) { // delete contact

			char buffer[200] = { 0 };
			Contact contact = { 0 };

			printf("enter the name to search for:\n");
			printf("> ");
			fgets(buffer, 99, stdin);
			remove_char(buffer, '\n');
			strncpy(contact.name, buffer, 49);

			if (deleteContact(&pList, contact) == TRUE)
				printf("contact found and deleted succesfully!\n");
			else
				fprintf(stderr, "error when finding and/or deleting contact.\n");\
		}
		else if (choice == 7) { // exit program

			return 0;
		}
		else { // error

			fprintf(stderr, "please enter a valid value.\n");
		}

		system("pause");
	}
}

Node* makeNode(Contact newData) {

	Node* newNode = (Node*)malloc(sizeof(Node));

	if (!newNode) {

		fprintf(stderr, "makeNode() failed to allocate size for a Node!\n");
		return NULL;
	}
	else {

		newNode->data = newData;
		newNode->pNext = NULL;

		return newNode;
	}	
}

Boolean insertContactInOrder(Node** pList, Contact newData) {

	// is the list empty so far?
	if (!*pList) { // if pList is null
		
		*pList = makeNode(newData);
		return TRUE;
	}

	// are we inserting in front?
	if (strcmp((*pList)->data.name, newData.name) > 0) {

		Node* newNode = makeNode(newData);
		newNode->pNext = *pList; // patch the link before breaking old ones
		*pList = newNode;
		return TRUE;
	}

	return insertContactInOrder(&(*pList)->pNext, newData); // resursive call
}

//// iterative approach
//Boolean insertContactInOrder(Node** pList, Contact newData) {
//
//	// is the list empty so far?
//	if ((*pList) == NULL) {
//
//		*pList = makeNode(newData);
//		return TRUE;
//	}
//
//	Node* pCur = *pList;
//
//	// insert at front?
//	if (strcmp(newData.name, pCur->data.name) < 0) {
//
//		Node* pNew = makeNode(newData);
//		pNew->pNext = pCur;
//		(*pList) = pNew;
//		return TRUE;
//	}
//	
//	while (pCur->pNext != NULL) {
//
//		if (strcmp(newData.name, pCur->pNext->data.name) < 0) {
//
//			// insert in between pCur and pNext
//			Node* pNew = makeNode(newData);
//			pNew->pNext = pCur->pNext;
//			pCur->pNext = pNew;
//			return TRUE;
//		}
//
//		pCur = pCur->pNext;
//	}
//
//	// insert at back
//	pCur->pNext = makeNode(newData);
//	return TRUE;
//}

Boolean deleteContact(Node** pList, Contact searchContact) {

	// first case: empty list
	if (!*pList) return FALSE;

	// second case: deleting the first contact
	if (!strcmp((*pList)->data.name, searchContact.name)) {

		Node* pTemp = *pList;
		*pList = (*pList)->pNext;

		free(pTemp);
		return TRUE;
	}

	return deleteContact(&(*pList)->pNext, searchContact); // recursive call
}

Boolean editContact(Node* pList, Contact searchContact) {

	if (!pList) return FALSE; // empty list

	// edit this contact
	if (!strcmp(pList->data.name, searchContact.name)) {

		char buffer[100] = { 0 };
		char input = 0;

#pragma region Edit Phone

		printf("edit phone number? (y/n)\n");
		input = get_char();

		if (toupper(input) == 'Y') { // edit
			printf("enter the new phone:\n");
			printf("> ");
			fgets(buffer, 99, stdin);
			remove_char(buffer, '\n');
			strcpy(pList->data.phone, buffer);
		}

#pragma endregion

#pragma region Edit Email

		printf("edit email? (y/n)\n");
		input = get_char();

		if (toupper(input) == 'Y') { // edit
			printf("enter the new email:\n");
			printf("> ");
			fgets(buffer, 99, stdin);
			remove_char(buffer, '\n');
			strcpy(pList->data.email, buffer);
		}

#pragma endregion

#pragma region Edit Title

		printf("edit title? (y/n)\n");
		input = get_char();

		if (toupper(input) == 'Y') { // edit
			printf("enter the new title:\n");
			printf("> ");
			fgets(buffer, 99, stdin);
			remove_char(buffer, '\n');
			strcpy(pList->data.title, buffer);
		}

#pragma endregion

		return TRUE;
	}

	return editContact(pList->pNext, searchContact); // recursive call
}

Boolean loadContacts(FILE* infile, Node** pList) {

	// not opened
	if (!infile) {

		fprintf(stderr, "infile has not been opened in loadContacts()!\n");
		return FALSE;
	}

	char buffer[300] = { 0 };
	while (!feof(infile)) {

		Contact newContact = { 0 };
		fgets(buffer, 299, infile); // get an entire line/contact

		// copy each field into it's relevent spot
		strncpy(newContact.name, strtok(buffer, ","), 49);
		strncpy(newContact.phone, strtok(NULL, ","), 11);
		strncpy(newContact.email, strtok(NULL, ","), 49);
		strncpy(newContact.title, strtok(NULL, ",\n"), 19); // get rid of newline character as well

		// check for success
		if (insertContactInOrder(pList, newContact) == FALSE) {

			fprintf(stderr, "insertContactInOrder() failed in loadContacts()!\n");
			return FALSE;
		}
	}

	return TRUE;
}

Boolean storeContacts(FILE* infile, Node* pList) {

	// not opened
	if (!infile) {
		fprintf(stderr, "infile has not been opened in storeContacts()!\n");
		return FALSE;
	}

	if (!pList) return TRUE; // end of list

	// print current
	fprintf(infile, "%s,", pList->data.name);
	fprintf(infile, "%s,", pList->data.phone);
	fprintf(infile, "%s,", pList->data.email);
	fprintf(infile, "%s\n", pList->data.title);

	return storeContacts(infile, pList->pNext); // recursive call
}

void printList(Node* pList) {

	if (!pList) return; // base case: null pointer

	// print current
	printContact(&pList->data);
	putchar('\n');

	printList(pList->pNext); // recursive call
}

void printContact(Contact* contact) {

	printf("name: %s\n", contact->name);
	printf("phone: %s\n", contact->phone);
	printf("email: %s\n", contact->email);
	printf("title: %s\n", contact->title);
}

void printMenu() {

	printf("welcome to lab 2, please select a choice:\n");
	printf("\t1. load from file\n");
	printf("\t2. save to file\n");
	printf("\t3. display contacts\n");
	printf("\t4. add contact\n");
	printf("\t5. edit contact\n");
	printf("\t6. delete contact\n");
	printf("\t7. exit program\n");
}

#pragma endregion