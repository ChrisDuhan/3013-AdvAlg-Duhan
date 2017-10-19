//********************************************************************
//      Project #3: Research Binary Search Tree
//      Name: Chris Duhan
//      Class: Advanced Algorithms and Data Structures
//      Instructor: Mr. Richard Simpson
//      Due Date: 10/25/2017
//********************************************************************
//      This program takes a file containing a line of numbers			//
//		and checks it for duplicated numbers. It takes 
//		non-duplicated numbers and stores them in a new array
//		while ignoring duplicates. The input file must have the
//		quantity of numbers on the line (minus one) as the first
//		number on the line. When telling the program the user 
//		must give the filename as well as the file extension.
//		It is simple enoungh to do without containing it to
//		it's own function so the worst case complexity that
//		the program could experience is O(2n), occuring if there
//		no unique numbers in the list. Otherwise the complexity
//		is O(n).
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
		x = rand() % 32000;
		insertAux(_root, x);
		cout << x << endl;
	}
}

//********************************************************************
//	ResearchBST:: ~ResearchBST()
//	Parameters: None
//	Complexity: O(1)
//	Default destructor. It calls the destroyTree() auxilliary method
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
void ResearchBST::insertAux(TreeNodeptr & tree, const int & item)//1-1
{
	if (tree == nullptr)
		tree = new treeNode(item);
	else
		if (item < tree->_value)
			insertAux(tree->_left, item);
		else
			insertAux(tree->_right, item);
	valueList.push_back(item);
	_size++;
}

//********************************************************************
//	ResearchBST::Insert()
//	Parameters: An intger that is the value to be 
//				stored in the node.
//	Complexity: O(1)
//	A publicly called function, it passes the integer that was passed
//	to it along to the insertAux() auxilliary method.
//********************************************************************
void ResearchBST::Insert(int value)//1-2
{
	insertAux(this->_root, value);
}

//********************************************************************
//	ResearchBST::inOrder()
//	Parameters: TreeNodeptr
//	Complexity O(n)
//	The auxilliary that prints the BST's values in accending order.
//********************************************************************
void ResearchBST::inOrder(TreeNodeptr tree)//2-1
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
//	Parameters: none
//	Complexity: O(1)
//	A publicly called function to print the BST in accending order.
//	Actually calls the inorder() auxilliary method.
//********************************************************************
void ResearchBST::InOrder()//2-2
{
	inOrder(this->_root);
}

//********************************************************************//
//	ResearchBST::SdeleteAux()
//	Parameters: pTreeNode to the tree and an int to delete
//	Complexity: O(n)
//	Auxilliary function called by Sdelete
//	Deletes a single int, x from the tree
//	May run n times if the tree is entirely unbalanced and the last node needs
//	to be deleted
//********************************************************************
void ResearchBST::SdeleteAux(TreeNodeptr & root, int x)//3-1
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

//********************************************************************//
//	ResearchBST::Sdelete()
//	Parameters: x: a single value to delete from the tree
//	Complexity: O(1)
//	public function, accepts a value, x, to be deleted, calls SdeleteAux()
//********************************************************************
void ResearchBST::Sdelete(int val)//3-2
{
	SdeleteAux(this->_root, val);
}

//********************************************************************//
//	ResearchBST::PdeleteAux()
//	Parameters: pTreeNode to the tree and an int to delete
//	Complexity: O(n)
//	Auxilliary function called by pDelete
//	Deletes a single int, x from the tree
//	May run n times if the tree is entirely unbalanced and the last node needs
//	to be deleted
//********************************************************************
void ResearchBST::PdeleteAux(TreeNodeptr & root, int x)//5-1 currently sdelete still
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

//********************************************************************//
//	ResearchBST::Pdelete()
//	Parameters: x: a single value to delete from the tree
//	Complexity: O(1)
//	public function, accepts a value, x, to be deleted, calls PdeleteAux()
//********************************************************************
void ResearchBST::Pdelete(int val)//5-2
{
	PdeleteAux(this->_root, val);
}

//********************************************************************//
//	ResearchBST::destroyTree()
//	Paprameters: pTreeNode to the BST
//	Complexity: O(n)
//	Auxilliary function for deleting every single node in the tree
//	called by the constructor
//********************************************************************
void ResearchBST::destroyTree(TreeNodeptr & tree)//4-1
{
	if (tree != nullptr)
	{
		destroyTree(tree->_left);
		destroyTree(tree->_right);
		delete tree;
		tree = nullptr;
	}
}

