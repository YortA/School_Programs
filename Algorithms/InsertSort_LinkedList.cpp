// Troy Andrews
// SDEV-345-81
// 1/31/2021
// Info: Week 3 Assignment (Insertion Sort)

#include <iostream>
#include <time.h>

//prototypes
class LinkedList
{
protected:
	struct ListNode
	{
		double val;
		ListNode* next;
		ListNode(double val, ListNode* next = nullptr)
		{
			this->val = val;
			this->next = next;
		}
	};
	ListNode* head;

public:
	LinkedList() { head = nullptr; }
	void add(double x);
	void getSort();

	// Why I am use a double pointer (pointer to pointer):
	// I need to pass a pointer as a parameter because
	// I am assigning the pointer to another pointer.
	void insertSort(ListNode** head);
	void sortedInsert(ListNode** head, ListNode* newNode);
	void printList();
	
};

void LinkedList::getSort()
{
	insertSort(&head);
}

void LinkedList::printList()
{
	ListNode* temp;
	temp = head;
	while (temp != nullptr)
	{
		std::cout << temp->val << ' ';
		temp = temp->next;
	}
	std::cout << std::endl;
}

void LinkedList::insertSort(ListNode** head)
{
	ListNode* sorted = nullptr;			// sorted is a temp hold so that we organize the linked list without affecting the main list
	ListNode* current = *head;

	while (current != nullptr)
	{
		ListNode* next = current->next;		// could probably have used the heap to manage this object better, but it works
		sortedInsert(&sorted, current);		// pass the pointer by reference so we can change the elements inside the function
		current = next;						// push forward our unsorted
	}
	*head = sorted;			// finally append our changes to the main
}

void LinkedList::sortedInsert(ListNode** head, ListNode* newNode)
{
	ListNode* current;

	// find our beginning point for our sorted/unsorted elements
	if (*head == nullptr || (*head)->val >= newNode->val)
	{
		newNode->next = *head;
		*head = newNode;
	}
	// here we will take our sorted and unsorted elements and arrange them
	else
	{
		current = *head;
		while (current->next != nullptr && current->next->val < newNode->val)		// current element is not empty, and the next element value is less than the current element
		{
			current = current->next;
		}
		// shift our sorted and unsorted elements
		newNode->next = current->next;
		current->next = newNode;
	}
}

void LinkedList::add(double x)
{
	// Checks for first element (head)
	if (head == nullptr)
	{
		head = new ListNode(x);
	}
	else
	{
		head = new ListNode(x, head);
	}
}


int main()
{
	
	clock_t tStart = clock();

	double dbarr[] = { 23,54,2,8,3.2,14,43,0,9,2 };
	int n = sizeof(dbarr) / sizeof(double);		// Get the number of elements in our array
	LinkedList list;

	// input all our elements into our linked list
	for (int i = 0; i < n; ++i)
	{
		list.add(dbarr[i]);
	}

	list.printList();
	
	// call our algorithm and re-print
	//list.getSort();
	list.printList();
	printf("Time taken: %.6fs\n", (double)(clock() - tStart) / CLOCKS_PER_SEC);
}