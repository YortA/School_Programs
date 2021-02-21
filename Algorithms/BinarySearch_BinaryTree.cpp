// Troy Andrews
// SDEV-340-81
// 12/13/2020
// Description: Simple Binary Search Tree Class
#include <iostream>
#include <vector>

// BinaryTree.h
class binarytree
{
private:
	struct binarynode
	{
		double val;
		binarynode* left;
		binarynode* right;
		binarynode(double val, binarynode* left = nullptr, binarynode* right = nullptr)
		{
			this->val = val;
			this->left = left;
			this->right = right;
		}
	};
	binarynode* root; // root is first val

	bool search(binarynode* tree, double x);
	void insert(binarynode*& tree, double x);					// pass-by-reference with our pointed to binary class
	void inOrder(binarynode* tree, std::vector<double>& v);

public:
	binarytree() { root = nullptr; }
	void insert(double x) { insert(root, x); }

	void inOrder(std::vector<double>& v) 
	{ 
		inOrder(root, v); 
	}

	bool search(double x) { return search(root, x); }
};

// BinaryTree.cpp
// Recursive search function that calls itself until we meet one of our conditions
bool binarytree::search(binarynode* tree, double x)
{
	while (tree)
	{
		if (tree->val == x)
		{
			return true;	// value exists inside our tree
		}
		else if (x < tree->val)
		{
			return search(tree->left, x);
		}
		else
		{
			return search(tree->right, x);
		}
	}
	// We couldn't find the value inside our binary tree, return false -- it does NOT exist.
	return false;
}

void binarytree::insert(binarynode*& tree, double x)
{
	// Node doesn't exist
	if (!tree)
	{
		tree = new binarynode(x);
		return;	// exit our function
	}

	if (tree->val == x)
	{
		std::cout << "'" << x << "' :" << "Number already exists in binary tree. Removing input..." << std::endl;
		return;
	}

	// tree is not empty -- choose our sub node (left or right)
	if (x < tree->val)
	{
		insert(tree->left, x);
	}
	else
	{
		insert(tree->right, x);
	}
}

void binarytree::inOrder(binarynode* tree, std::vector<double>& v)
{
	if (tree)
	{
		inOrder(tree->left, v);
		v.push_back(tree->val);

		inOrder(tree->right, v);
	}
}


// main.cpp
int main()
{
	binarytree tree;
	std::vector<double> vectordoubles;

	tree.insert(1.1);
	tree.insert(9.9);
	tree.insert(9.9);		// Test to see if our insert can detect duplicates.
	tree.insert(3.3);

	std::cout << "Input value to search." << std::endl;
	double input;
	std::cin >> input;
	if (tree.search(input))
	{
		std::cout << "Value found." << std::endl;
	}
	else
	{
		std::cout << "Value not found." << std::endl;
	}

	tree.inOrder(vectordoubles);
	std::cout << "Binary Tree Values::\t";
	for (int i = 0; i < vectordoubles.size(); i++)
	{
		std::cout << vectordoubles[i] << ", ";
	}
}