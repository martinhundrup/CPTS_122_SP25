/*
 * File: lab2.h
 * Author: Martin Hundrup
 * Professor: Andy O'Fallon
 * Class: CPT_S 122, Spring 2025
 * Assignment: Lab 2
 * Created: January 19, 2025
 */


// guard code
#ifndef LAB2_H
#define LAB2_H

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h> // REQUIRED for malloc
#include <string.h>

#include "../Utility.h" // my own little library

// used for a proper boolean value type in C
typedef enum boolean
{
	FALSE, TRUE
} Boolean;

// we want to preallocate memory using [] rather than * to ensure every struct has the same size
typedef struct contact
{
	char name[50];
	char phone[12]; // ex: 18005557577
	char email[50];
	char title[20];

} Contact;

// our linked list
typedef struct node
{
	Contact data;
	struct node* pNext;
} Node;

/*
    Performs a use case for a linked list.
*/
void task_1();

/*
    Allocates space for a Node on the heap and initializes it with a Contact.

    @param newData The contact to store in the node.
    @return The address of the start of the block of memory on the heap or NULL if no memory was allocated.
*/
Node* makeNode(Contact newData);

/*
    Uses makeNode() to allocate space for a new Node and inserts it into the list alphabetically based on name.

    @param pList A pointer to the list structure.
    @param newData The contact to store in the node.
    @return TRUE if memory was allocated for a Node; FALSE otherwise.
*/
Boolean insertContactInOrder(Node** pList, Contact newData);

/*
    Deletes a Contact in the list based on the name field; deletes the first occurrence of the name.

    @param pList A pointer to the list structure.
    @param searchContact The contact to search for and delete.
    @return TRUE if the Contact was found and deleted; FALSE otherwise.
*/
Boolean deleteContact(Node** pList, Contact searchContact);

/*
    Edits a Contact in the list based on the name field; edits the first occurrence of the name.

    @param pList A pointer to the list structure.
    @param searchContact The contact to search for and edit.
    @return TRUE if the Contact was found and edited; FALSE otherwise.
*/
Boolean editContact(Node* pList, Contact searchContact);

/*
    Loads all Contact information from the given file into the list in alphabetical order based on the name.

    @param infile A pointer to the file containing the contacts.
    @param pList A pointer to the list structure.
    @return TRUE if all Contacts were successfully loaded; FALSE otherwise.
*/
Boolean loadContacts(FILE* infile, Node** pList);

/*
    Stores all Contact information from the list into the given file.

    @param infile A pointer to the file where contacts will be stored.
    @param pList A pointer to the list structure.
    @return TRUE if all Contacts were successfully stored; FALSE otherwise.
*/
Boolean storeContacts(FILE* infile, Node* pList);

/*
    Prints all contact information in the list.

    @param pList A pointer to the list structure.
    @return Nothing.
*/
void printList(Node* pList);

/*
    Prints the atributes of a contact to the terminal.

    @param a pointer to the contact to print.
*/
void printContact(Contact* contact);

/*
    Displays the program menu.

    @return Nothing.
*/
void printMenu();

#endif