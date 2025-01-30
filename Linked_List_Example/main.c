#include "linked_list.h"

int main() {


	struct node* pList = NULL;

	insert_order(&pList, 5);
	insert_order(&pList, 1);
	insert_order(&pList, 2);
	insert_order(&pList, 7);
	insert_order(&pList, 6);
	insert_order(&pList, 3);
	insert_order(&pList, 4);

	//print_reverse(get_pTail(pList));

	print_list(pList);

	//print_list(reverse_list(&pList));


	return 0;
}