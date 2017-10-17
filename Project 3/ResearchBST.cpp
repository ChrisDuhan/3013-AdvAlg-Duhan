#include <iostream>
#include <random>
#include "ResearchBST.h"

using namespace std;

ResearchBST::ResearchBST(int randgen)
{

}

ResearchBST::~ResearchBST()
{
	destroyTree(this->_root);
}

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

void ResearchBST::Insert(int value)//1-2
{
	insertAux(this->_root, value);
}

void ResearchBST::inOrder(TreeNodeptr tree)//2-1
{
	if (tree != nullptr)
	{
		inOrder(tree->_left);
		cout << tree->_value << endl;
		(tree->_right);
	}
}

void ResearchBST::InOrder()//2-2
{
	inOrder(this->_root);
}

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

void ResearchBST::Sdelete(int val)//3-2
{
	SdeleteAux(this->_root, val);
}

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

void ResearchBST::Pdelete(int val)//5-2
{
	SdeleteAux(this->_root, val);
}

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
