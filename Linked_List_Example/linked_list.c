#include "linked_list.h"

struct node* make_node(int data) {

	struct node* pNew = (struct node*)malloc(sizeof(struct node));

	if (!pNew) return NULL; // defensive programming

	pNew->pNext = NULL;
	pNew->pPrev = NULL;
	pNew->data = data;

	return pNew;
}

void insert_front(struct node** pHead, int data) {

	if (*pHead == NULL) { // case 1: empty list
		*pHead = make_node(data);
		return; // we're done
	}

	// case 2: not empty
	struct node* pNew = make_node(data);

	pNew->pNext = *pHead; // step 1
	(*pHead)->pPrev = pNew; // step 2
	*pHead = pNew; // step 3
}

void insert_back(struct node** pHead, int data) {

	if (*pHead == NULL) { // case 1: empty list
		*pHead = make_node(data);
		return; // we're done
	}

	struct node* pCur = *pHead;

	while (pCur->pNext != NULL) {

		pCur = pCur->pNext;
	}

	struct node* pNew = make_node(data);
	pCur->pNext = pNew;
	pNew->pPrev = pCur;
}

void insert_order(struct node** pHead, int data) {

	if (*pHead == NULL) { // case 1: empty list
		*pHead = make_node(data);
		return; // we're done
	}

	// case 2: insert at front
	if (data < (*pHead)->data) {
		insert_front(pHead, data);
		return;
	}

	struct node* pCur = *pHead;
	while (pCur->pNext->data < data) {		

		pCur = pCur->pNext;

		if (pCur->pNext == NULL) {
			insert_back(pHead, data);
			return;
		}
	}

	struct node* pNew = make_node(data);

	pNew->pNext = pCur->pNext;
	pNew->pPrev = pCur;

	pCur->pNext = pNew;
	pNew->pNext->pPrev = pNew;
}

void print_list (struct node* pHead) {

	if (pHead == NULL) return;
	printf("node value: %d\n", pHead->data);

	print_list(pHead->pNext);
}

void print_reverse(struct node* pTail) {

	if (pTail == NULL) return;
	printf("node value: %d\n", pTail->data);

	print_reverse(pTail->pPrev);
}

// does NOT work for doubly linked list
struct node* reverse_list(struct node** pHead) {

	if (*pHead == NULL) return NULL; // empty list
	if ((*pHead)->pNext == NULL) return *pHead; // single item in list

	struct node* pCur = *pHead;
	struct node* pNext = pCur->pNext;
	struct node* pPrev = NULL;
	while (pNext != NULL) { // garantee we stay within the bounds of the list

		pCur->pNext = pPrev; // reverse link

		// set up for next iteration
		pPrev = pCur;
		pCur = pNext;
		pNext = pCur->pNext;
	}

	pCur->pNext = pPrev; // final reverse link
	(*pHead) = pCur; // set new head
	return pCur;
}

struct node* get_pTail(struct node* pHead) {

	if (pHead == NULL) { // case 1: empty list
		return NULL;
	}

	struct node* pCur = pHead;

	while (pCur->pNext != NULL) {

		pCur = pCur->pNext;
	}

	return pCur;
}