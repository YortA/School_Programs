// Troy Andrews
// SDEV-340-81
// 12/6/2020
// Description: File Reverser
#include <iostream>
#include <fstream>

// charstack.h
class charstack
{
protected:
	struct stacknode
	{
		char val;
		stacknode* next;
		stacknode(char val, stacknode* next = nullptr)
		{
			this->val = val;
			this->next = next;
		}
	};
	stacknode* head;

public:
	charstack() { head = nullptr; }
	void push(char x);
	void pop(char& x);
	bool isEmpty();
};

// charstack.cpp
void charstack::push(char x)
{
	head = new stacknode(x, head);
}

void charstack::pop(char& x)
{
	if (isEmpty())
	{
		std::cout << "Stack is empty." << std::endl;
	}
	else
	{
		x = head->val;
		stacknode* tempval = head;
		head = head->next;
		delete tempval;
	}
}

bool charstack::isEmpty()
{
	if (head == nullptr)
		return true;
	else
		return false;
}

// prototypes/declares
void readChars(std::fstream& charIn, charstack& charStack);
void writeChars(std::fstream& charOut, charstack& charStack);

int main()
{
	charstack chStack;

	//in
	std::fstream charsIn;
	charsIn.open("week13_in.txt");
	if (!charsIn)
	{
		std::cerr << "ERROR! File failed to open!" << std::endl;
		return 1;
	}
	readChars(charsIn, chStack);
	charsIn.close();

	//out
	std::fstream charsOut;
	charsOut.open("week13_out.txt");
	if (!charsOut)
	{
		std::cerr << "ERROR! File failed to open!" << std::endl;
		return 2;
	}
	writeChars(charsOut, chStack);
	charsOut.close();

	std::cout << "\nSuccess!" << std::endl;
}

// Defs
// Reads our chars from our file and pushes on stack
void readChars(std::fstream& charIn, charstack& charStack)
{
	char ch;
	while (charIn.get(ch))
	{
		std::cout << ch << '\t';
		charStack.push(ch);
	}
	std::cout << '\n';
}

// Reads from our stack and pops each character off of it and writes to our file
void writeChars(std::fstream& charOut, charstack& charStack)
{
	char ch;
	while (!charStack.isEmpty())
	{
		charStack.pop(ch);
		std::cout << ch << '\t';
		charOut.put(ch);
	}
}