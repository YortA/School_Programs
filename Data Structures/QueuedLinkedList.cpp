// Troy Andrews
// SDEV-345-81
// 2/21/2021
// Info: Week 6 Assignment (Queued Linked List)

#include <iostream>

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
	bool isEmpty();
	void addFront(double x);
	double popFront();
	void pushBack(double x);
	

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

bool DoubleLinkedList::isEmpty()
{
	if (head == nullptr)
		return true;
	else
		return false;
}

double DoubleLinkedList::popFront()
{
	// We created a temporary node to save the value to, 
	// we can manipulate this if we want -- but for now it's just the val
	ListNode* frontnode = head;
	double temp = frontnode->val;

	if (head->next == nullptr)
		tail = nullptr;
	head = head->next;

	delete frontnode;
	return temp;
}

void DoubleLinkedList::pushBack(double x)
{
	ListNode* backnode = new ListNode(x);
	
	if (head == nullptr)
		head = backnode;
	else
		tail->next = backnode;
	tail = backnode;
}

// prototypes
void menu();

int main()
{
	menu();
}

void menu()
{
	DoubleLinkedList* testQueue = new DoubleLinkedList;
	
	for (int i = 0; i < 10; ++i)
	{
		testQueue->addFront(i);
	}

	char option{};
	double input{};
	bool repeatMenu = true;

	while (repeatMenu)
	{
		std::cout << "### OPTIONS ###\n";
		std::cout << "1. Check queue\n";
		std::cout << "2. Pop front\n";
		std::cout << "3. Push back\n";
		std::cout << "4. Display queue" << std::endl;

		std::cin >> option;
		std::cout << std::endl;

		switch (option)
		{
		case '1':
			if (testQueue->isEmpty())
				std::cout << "EMPTY\n";
			else
				std::cout << "NOT EMPTY" << std::endl;
			break;

		case '2':
			if (testQueue->isEmpty())
				std::cout << "List is empty, please push a value (option 3.)" << std::endl;
			else
				std::cout << testQueue->popFront() << " popped off." << std::endl;
			break;

		case '3':
			std::cout << "Input value: ";
			std::cin >> input;
			testQueue->pushBack(input);
			break;

		case '4':
			testQueue->printList();
			break;
			
		case 'z': case 'Z':
			std::cout << "Exiting..." << std::endl;
			repeatMenu = false;
			break;
		default:
			std::cout << option << " is an unknown input, try again." << std::endl;
		}
	}
}