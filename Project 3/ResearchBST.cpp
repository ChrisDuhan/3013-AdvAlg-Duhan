//********************************************************************
//  Project #3: Research Binary Search Tree
//  Name: Chris Duhan
//  Class: Advanced Algorithms and Data Structures
//  Instructor: Mr. Richard Simpson
//  Due Date: 10/25/2017
//********************************************************************
//  This class is designed for the researching of Binary Search Trees
//	(BST)s. 
//	I will refer to the pointer that points to the root node of a
//	given tree as TreeNodeptr.
//	When the notation O(h) is seen it should be interpreted as being
//	as complex as the length of the longest "branch" in the tree which
//	at worst could be n, the total number of nodes in the tree.
//
//********************************************************************

#include <iostream>
#include <cstdlib>
#include "ResearchBST.h"

using namespace std;

//********************************************************************
//	ResearchBST::ResearchBST()
//	Parameters: An integer that represents the amount of random
//				numbers to put into the BST.
//	Complexity: O(n)
//	The default constructor. In this case it will create the BST
//	with n nodes populated with pseudo-random integers.
//********************************************************************
ResearchBST::ResearchBST(int n)
{
	int x;
	_root = nullptr;
	_size = 0;

	for (int i = 0; i < n; ++i)
	{
		x = rand() % VALUESIZE;
		Insert(x);
	}
}

//********************************************************************
//	ResearchBST:: ~ResearchBST()
//	Parameters: None
//	Complexity: O(1)
//	Standard destructor. It calls the destroyTree() auxilliary method
//********************************************************************
ResearchBST::~ResearchBST()
{
	destroyTree(this->_root);
}

//********************************************************************
//	ResearchBST::insertAux()
//	Parameters: TreeNodeptr, and a constant reference to an intger 
//				that is the value to be stored in the node.
//	Complexity: O(n)
//	Recieves the value to be stored in a new node from the public
//	Insert() method, finds the appropriate point to create the new
//	node, creates it and initializes its value to the passed in
//	integer.
//********************************************************************
void ResearchBST::insertAux(TreeNodeptr & tree, const int & item)
{
	if (tree == nullptr)
		tree = new treeNode(item);
	else
		if (item < tree->_value)
			insertAux(tree->_left, item);
		else
			insertAux(tree->_right, item);
}

//********************************************************************
//	ResearchBST::Insert()
//	Parameters: An intger that is the value to be 
//				stored in the node.
//	Complexity: O(1)
//	A publicly called function, it passes the integer that was passed
//	to it along to the insertAux() auxilliary method.
//********************************************************************
void ResearchBST::Insert(int value)
{
	insertAux(this->_root, value);
	valueList.push_back(value);
	++_size;
}

//********************************************************************
//	ResearchBST::inOrder()
//	Parameters: TreeNodeptr
//	Complexity O(n)
//	The auxilliary method that prints the BST's values in accending 
//	order.
//********************************************************************
void ResearchBST::inOrder(TreeNodeptr tree)
{
	if (tree != nullptr)
	{
		inOrder(tree->_left);
		cout << tree->_value << endl;
		(tree->_right);
	}
}

//********************************************************************
//	ResearchBST::InOrder()
//	Parameters: None
//	Complexity: O(1)
//	A publicly called function to print the BST in accending order.
//	Actually calls the inorder() auxilliary method.
//********************************************************************
void ResearchBST::InOrder()
{
	inOrder(this->_root);
}

//********************************************************************
//	ResearchBST::SdeleteAux()
//	Parameters: TreeNodeptr and the integer value of the node to be
//				deleted.
//	Complexity: O(h)
//	The auxilliary method that find the node containing the value to
//	be deleted and uses a different way to remove it depending on
//	whether the node to be deleted has zero, one or two children.
//	It is the Successor delete method so to find the successor node it
//	moves to the right of the node once then as far left as it can
//	without going right again.
//********************************************************************
void ResearchBST::SdeleteAux(TreeNodeptr & root, int x)
{
	if (root != nullptr)
	{
		TreeNodeptr tempPtr, predPtr;

		if (x < root->_value)
			SdeleteAux(root->_left, x);
		else if (x > root->_value)
			SdeleteAux(root->_right, x);
		else
		{	// we have found it so lets delete it
			// tree points at it right!?
			// If No children we just delete it
			if (root->_left == nullptr && root->_right == nullptr)
			{
				delete(root);
				root = nullptr; // what happens when we
				return;       // return here! important!
			}
			// Check to see if the node to delete has only one child
			if (root->_left == nullptr)
			{	// Then splice in the right side
				tempPtr = root->_right;
				delete root;
				root = tempPtr;
			}
			else if (root->_right == nullptr)
			{	// splice left
				tempPtr = root->_left;
				delete(root);
				root = tempPtr;
			}
			else
				// both children exist! so...
				// Here root has two children
				// We first find the successor
			{
				predPtr = root;
				tempPtr = root->_right; // Go right
										// and the all the way to the left
				while (tempPtr->_left != nullptr)
				{
					predPtr = tempPtr;
					tempPtr = tempPtr->_left;
				}
				root->_value = tempPtr->_value; // Copy the value up to the root
				if (root->_right == tempPtr)
					root->_right = tempPtr->_right;
				else
					predPtr->_left = tempPtr->_right;

				delete tempPtr;
			}
		}
	}
}

//********************************************************************
//	ResearchBST::Sdelete()
//	Parameters: the value in the node to be deleted.
//	Complexity: O(1)
//	A publicly called function that calls SdeleteAux() and passes it
//	the value in the node to be deleted.
//********************************************************************
void ResearchBST::Sdelete(int val)
{
	SdeleteAux(this->_root, val);
}

//********************************************************************
//	ResearchBST::PdeleteAux()
//	Parameters: TreeNodeptr and the integer value of the node to be
//				deleted.
//	Complexity: O(h)
//	The auxilliary method that find the node containing the value to
//	be deleted and uses a different way to remove it depending on
//	whether the node to be deleted has zero, one or two children.
//	It is the Predecessor delete method so to find the predecessor
//	node it moves to the left of the node once then as far right as 
//	it can without going left again.
//********************************************************************
void ResearchBST::PdeleteAux(TreeNodeptr & root, int x)
{
	if (root != nullptr)
	{
		TreeNodeptr tempPtr, predPtr;

		if (x < root->_value)
			PdeleteAux(root->_left, x);
		else if (x > root->_value)
			PdeleteAux(root->_right, x);
		else
		{	// we have found it so lets delete it
			// tree points at it right!?
			// If No children we just delete it
			if (root->_left == nullptr && root->_right == nullptr)
			{
				delete(root);
				root = nullptr; // what happens when we
				return;       // return here! important!
			}
			// Check to see if the node to delete has only one child
			if (root->_left == nullptr)
			{	// Then splice in the right side
				tempPtr = root->_right;
				delete root;
				root = tempPtr;
			}
			else if (root->_right == nullptr)
			{	// splice left
				tempPtr = root->_left;
				delete(root);
				root = tempPtr;
			}
			else
				// both children exist! so...
				// Here root has two children
				// We first find the successor
			{
				predPtr = root;
				tempPtr = root->_left; // Go left
									   // and the all the way to the right
				while (tempPtr->_right != nullptr)
				{
					predPtr = tempPtr;
					tempPtr = tempPtr->_right;
				}
				root->_value = tempPtr->_value; // Copy the value up to the root
				if (root->_left == tempPtr)
					root->_left = tempPtr->_left;
				else
					predPtr->_right = tempPtr->_left;

				delete tempPtr;
			}
		}
	}
}

//********************************************************************
//	ResearchBST::Pdelete()
//	Parameters: the value in the node to be deleted.
//	Complexity: O(1)
//	A publicly called function that calls PdeleteAux() and passes it
//	the value in the node to be deleted.
//********************************************************************
void ResearchBST::Pdelete(int val)
{
	PdeleteAux(this->_root, val);
}

//********************************************************************
//	ResearchBST::RandDelInsPair()
//	Parameters: An int used to identify what type of delete to use
//	Complexity: O(1)
//	Randomly selects a value to be deleted from both the tree and 
//	the vector, and then inserts a new node.
//********************************************************************
void ResearchBST::RandDelInsPair(int dType) // check this
{
	int randIndex = rand() % valueList.size();
	int valueAt = valueList[randIndex];
	int insVal = rand() % VALUESIZE;
	valueList[randIndex] = insVal;
	if (dType == 1)
		PdeleteAux(_root, valueAt);
	else
		SdeleteAux(_root, valueAt);
	insertAux(this->_root, insVal);
}

//********************************************************************
//	ResearchBST::iplAux()
//	Parameters: TreeNodeptr and an int to total the ipl.
//	Complexity: O(n)
//	The auxilliary function that sums up the "weights" for each node
//	in the tree.
//********************************************************************
int ResearchBST::iplAux(TreeNodeptr & root, int val)
{
	if (root == nullptr)
		return 0;
	return(val + iplAux(root->_right, ++val) + iplAux(root->_left, ++val));
}

//********************************************************************
//	ResearchBST::IPL()
//	Parameters: None
//	Complexity: O(1)
//	A publicly called function that calls iplAux() and passes it
//	the accumulator.
//********************************************************************
int ResearchBST::IPL()
{
	int val = 0;
	return iplAux(this->_root, val);
}
//********************************************************************
//	ResearchBST::destroyTree()
//	Paprameters: TreeNodeptr
//	Complexity: O(n)
//	The auxilliary function that deletes every node in the tree.
//	It's called by the destructor.
//********************************************************************
void ResearchBST::destroyTree(TreeNodeptr & tree)
{
	if (tree != nullptr)
	{
		destroyTree(tree->_left);
		destroyTree(tree->_right);
		delete tree;
		tree = nullptr;
	}
}
