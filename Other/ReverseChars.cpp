// Troy Andrews
// SDEV-345-81
// 2/7/2021
// Info: Week 4 Assignment (Stacks & Queues)

// I believe this is the "point" of this exercise, to be able to properly use a stack
// and its nodes in order to manipulate it. I could have created a separate class
// that forward declared the function but I see little to no purpose.

#include <iostream>

// Container for our stack nodes
class StackTest
{
protected:
	// Acts as a LIFO structure
	struct StackNode
	{
		char letter;
		StackNode* next;
		StackNode(char letter, StackNode* next = nullptr)
		{
			this->letter = letter;
			this->next = next;
		}
	};
	StackNode* head;

public:
	StackTest() { head = nullptr; }
	void push(char x);
	void pop(char& x);
	bool isEmpty();
	void reverser(char* strarray);

};

void StackTest::push(char x)
{
	head = new StackNode(x, head);
}

void StackTest::pop(char& x)
{
	if (isEmpty())
	{
		std::cout << "Stack is empty." << std::endl;
	}
	else
	{
		x = head->letter;
		//StackNode* temp = head;
		head = head->next;
		//delete temp;
	}
}

bool StackTest::isEmpty()
{
	if (head == nullptr)
		return true;
	else
		return false;
}

// We'll pass by pointer (reference with array.
void StackTest::reverser(char* strarray)
{
	for (int i = 0; strarray[i] != '\0'; ++i)	// check for null terminator char
	{
		this->push(strarray[i]);
	}

	// Pop our c string letters out of our stack
	for (int i = 0; strarray[i] != '\0'; ++i)
	{
		this->pop(strarray[i]);
	}
}

// Prototypes
void reverseWord();

int main()
{
	reverseWord();
}

void reverseWord()
{
	char* input = new char[256];

	StackTest stackreverse;

	std::cout << "Input a word to reverse: ";
	fgets(input, 100, stdin);

	stackreverse.reverser(input);

	std::cout << input;
}