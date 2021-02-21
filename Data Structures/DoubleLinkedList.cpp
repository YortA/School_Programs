// Troy Andrews
// SDEV-345-81
// 2/13/2021
// Info: Week 5 Assignment (Linked List)

#include <iostream>
#include<windows.h>

class DoubleLinkedList
{
protected:
	struct ListNode
	{
		double val;
		ListNode* next;
		ListNode* prev;
		ListNode(double val, ListNode* next = nullptr, ListNode* prev = nullptr)
		{
			this->val = val;
			this->next = next;
			this->prev = prev;
		}
	};
	ListNode* head;
	ListNode* tail;

public:
	DoubleLinkedList() : head(nullptr), tail(nullptr) {};
	void addFront(double x);
	void addBack(double x);
	void insertNode(double x, int pos);
	void deleteNode(double x);


	double search(double x);
	void printList()
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
};

void DoubleLinkedList::addFront(double x)
{
	ListNode* node = new ListNode(x);

	if (head == nullptr)
	{
		// there must be a head and tail, if the list is empty we will make one.
		head = node;
		tail = node;
	}
	else
	{
		node->next = head;
		head = node;
		node->next->prev = node;
	}
}

void DoubleLinkedList::addBack(double x)
{
	ListNode* node = new ListNode(x);

	if (tail->next == nullptr)
	{
		tail->next = node;
		tail = node;
	}
}

// Insert between two nodes (we insert 1 to the right of our position
void DoubleLinkedList::insertNode(double x, int pos)
{
	ListNode* temp = head;

	for (int i = 0; i < pos; ++i)
	{
		temp = temp->next;		// we've found our pos.
	}

	// Insert our node with the input value in front of our current position and assign
	ListNode* newnode = new ListNode(x, temp->next, temp->prev);
	temp->next = newnode;
}
void DoubleLinkedList::deleteNode(double x)
{
	ListNode* temp = head;
	for (int i = 0; i < x - 1; ++i)
	{
		temp = temp->next;		// we've found our pos.
	}

	// re-link our node and then delete
	ListNode* ptr = temp->next;		// ptr to node to be deleted from our linked list
	temp->next = temp->next->next;
	temp->prev = temp->prev->prev;
	delete ptr;
}

double DoubleLinkedList::search(double x)
{
	int element = 0;

	if (head == nullptr)
	{
		return -1;
	}
	else
	{
		ListNode* nodePtr = head;
		while (nodePtr != nullptr)
		{
			// We found a matching value.
			if (nodePtr->val == x)
			{
				return element;		// return element number
			}
			nodePtr = nodePtr->next;
			element++;
		}
		return -1;	// we found nothing, exit the function
	}
}

int main()
{
	DoubleLinkedList* elevator = new DoubleLinkedList;

	for (int i = 0; i < 10; ++i)
	{
		elevator->addFront(i);
	}

	std::cout << "Original: ";
	elevator->printList();
	elevator->insertNode(666, 3);

	std::cout << "Insert: ";
	elevator->printList();

	double val{};
	std::cout << "Input a value to search and delete: ";
	std::cin >> val;

	std::cout << "Search & Delete: ";
	elevator->deleteNode(elevator->search(val));
	elevator->printList();
}