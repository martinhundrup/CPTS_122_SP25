#ifndef LAB3_H
#define LAB3_H

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

struct node {

	int data;

	struct node* pNext;
	struct node* pPrev;
};

struct node* make_node(int data);

void insert_front(struct node** pHead, int data);

void insert_back(struct node** pHead, int data);

void insert_order(struct node** pHead, int data);

void print_list(struct node* pHead);

void print_reverse(struct node* pHead);

struct node* get_pTail(struct node* pHead);

struct node* reverse_list(struct node** pHead);


#endif