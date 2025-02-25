#include "ListApp.h"
#include "TestList.h"

int main(void)
{
	TestList testList;
	testList.runTests();

	// Start with debugging this project! "Step Into" each statement to answer the questions!
	// Question 1: what function is called in the statement below?
	ListNode n1;

	/*
		Answer: 
		The ListNode(int) constructor.
	*/

	// Question 2: what function is called in the statement below?
	ListNode n2(42); // shallow or deep copy?

	/*
		Answer:
		The same ListNode(int) funtion is called, implying a shallow copy.
		However, because we are copying an integer, the assignment '=' is a deep copy.
	*/

	// Question 3: what function is called in the statement below?
	ListNode n3(n2); // shallow or deep copy?

	/*
		Answer:
		The ListNode(ListNode&) copy constructor is called.
		This is a deep copy, as new memory is allocated.
	*/

	// Question 4: what function is called in the statement below?
	ListNode n4 = n3; // shallow or deep copy?

	/*
		Answer:
		The same ListNode(ListNode&) copy constructor is called.
		This implies it is a deep copy as well.
	*/

	ListNode n5;
	// Question 5: what function/operator is called in the statement below?
	n5 = n4; // did we explicitly implement this function/operator? 

	/*
		Answer:
		The assignment operator '=' is called.
		We have not implemented this operator.
	*/

	// Question 6: what function is called in the statement below?
	List l1;

	/*
		Answer:
		The List() default constructor.
	*/

	// make sure that you finish implementing the copy constructor for the List object before you try to 
	// execute the next statement!
	// Question 7: what function is called in the statement below? What would happen if we did not 
	//             explicitly implement the function? Would the compiler generated one be good enough?
	List l2 = l1; // shallow or deep copy?
	
	/*
		Answer:
		The List(List&) copy constructor is called.
		Had there not been this copy constructor, the compiler generated one would be called.
		The compiler generated one is a shallow copy, while ours is a deep copy.
	*/
	
	// Question 8: what would happen if a shallow copy constructor is used, instead of a deep copy constructor, 
	//             when the destructor for each list object is implicily invoked? l2 and l1 would have the same
	//             address stored in the head pointer, and thus, one of the lists would be freed and when the other went
	//             out of scope, the destructor would try to access already freed memory (a dangling pointer situation)!

	/*
		Answer:
		Andy answered this for us.
	*/

	List l3;
	// make sure that you finish implementing the overloaded assignment for the List object before you try to 
	// execute the next statement!
	// Question 9: what function is called in the statement below? What would happen if we did not 
	//             explicitly implement the function? Would the compiler generated one be good enough?
	l3 = l2; // shallow or deep copy? 
	
	/*
		Answer:
		Had we not defined the assignment operator '=' overload, a compiler generated one would be called.
		The compiler generated one would be a shallow copy.

	*/

	// Question 10: what would happen if a shallow copy assignment is used, instead of a deep copy assignment, 
	//              when the destructor for each list object is implicily invoked? l3 and l2 would have the same
	//              address stored in the head pointer, and thus, one of the lists would be freed and when the other went
	//              out of scope, the destructor would try to access already freed memory (a dangling pointer situation)!

	/*
		Answer:
		Andy has, once again, answered this for us.
	*/

	// Question 11: how does the List destructor free up the nodes? You will need to visit "List.cpp" to answer this question!

	/*
		Answer:
		It recursively deletes each node in the list.
	*/

	ListApp app;

	app.runApp();

	return 0;
}