//********************************************************************
//  Project #4: MinHeap priority queue
//  Name: Chris Duhan
//  Class: Advanced Algorithms and Data Structures
//  Instructor: Mr. Richard Simpson
//  Due Date: 11/10/2017
//********************************************************************
//  This class is a simple MinHeap. Designed to solve a UVa problem
//	without using the priority queue in the standard template library.
//
//********************************************************************
#include "Heap.h"
#include <iostream>
#include <vector>

using namespace std;

//********************************************************************
//	Heap::Heap()
//	Parameters: None
//	Complexity: O(1)
//	The default constructor. Puts a placeholder value in the zeroth
//	index so the parent, left and right calculations don't get thrown
//	off with multiplication by zero.
//********************************************************************
Heap::Heap()
{
	heap.push_back(-1); // occupies index 0
}

//********************************************************************
//	Heap::Heap()
//	Parameters: A vector of integers
//	Complexity: O(n)?
//	A parameterized constructor. Puts a placeholder value in the 
//	zeroth index so the parent, left and right calculations don't get 
//	thrown off with multiplication by zero. Then it copies the 
//	contents of the parameter vector to itself using the Insert()
//	method for each value.
//********************************************************************
Heap::Heap(vector<int> input)
{
	heap.push_back(-1); // occupies index 0
	for (int i = 0; i < input.size(); ++i)
	{
		heap.push_back(input[i]);
	}
}

//********************************************************************
//	Heap::~Heap()
//	Parameters: None
//	Complexity: N/A
//	The default destructor, but it doesn't need to be used in this 
//	case.
//********************************************************************
Heap::~Heap()
{
}

//********************************************************************
//	Heap::Size()
//	Parameters: None
//	Complexity: O(1)
//	Returns the size of the data in the underlying vector that is
//	the heap. I.E. the sized of the vector minus one to account for 
//	the placeholer in index zero.
//********************************************************************
int Heap::Size()
{
	return heap.size() - 1;
}

//********************************************************************
//	Heap::Empty()
//	Parameters: None
//	Complexity: O(1)
//	Returns a boolean value based on on the value of Size().
//********************************************************************
bool Heap::Empty()
{
	if (Size() == 0)
		return 1;
	return 0;
}

//********************************************************************
//	Heap::Insert()
//	Parameters: An integer that is the value to be added to the heap
//	Complexity: O(log n)
//	Pushes the value onto the back of the underlying vector and calls
//	makeHeap() on it.
//********************************************************************
void Heap::Insert(int i)
{
	heap.push_back(i);
	makeHeap(Size());
}

//********************************************************************
//	Heap::Extract()
//	Parameters: None
//	Complexity: O(1)?
//	Notes the value of the first item in the heap, then swaps it with
//	the value in the last index. Removes the new last item and calls
//	Heapify() on the swapped position to go back to heap order.
//	Then returns the value of the old first item.
//********************************************************************
int Heap::Extract()
{
	int front = heap[1];
	swap(heap[1], heap[Size()]);
	heap.pop_back();
	Heapify(1);
	return front;
}

//********************************************************************
//	Heap::Parent()
//	Parameters: An interger that is the index of the value we are
//				interested in.
//	Complexity: O(1)
//	Due to the nature of how values are stored in a heap we can 
//	divide a given index by two to find the index of its parent.
//	The binary shift operation is a faster way to get the same 
//	result.
//********************************************************************
inline int Heap::Parent(int i)
{
	return i >> 1;
}

//********************************************************************
//	Heap::Left()
//	Parameters: An interger that is the index of the value we are
//				interested in.
//	Complexity: O(1)
//	Due to the nature of how values are stored in a heap we can 
//	multiply a given index by two to find the index of its left child.
//	The binary shift operation is a faster way to get the same 
//	result.
//********************************************************************
inline int Heap::Left(int i)
{
	return i << 1;
}

//********************************************************************
//	Heap::Right()
//	Parameters: An interger that is the index of the value we are
//				interested in.
//	Complexity: O(1)
//	Due to the nature of how values are stored in a heap we can 
//	multiply a given index by two then add one to find the index of 
//	its right child. (The right children are always odd number indices)
//	The binary shift operation is a faster way to get the same 
//	result.
//********************************************************************
inline int Heap::Right(int i)
{
	return (i << 1) + 1;
}

//********************************************************************
//	Heap::makeHeap()
//	Parameters: An integer that is the index to begin at
//	Complexity: O(log n)
//	Checks the value at the index passed in and the value at the 
//	parent index of the first index and compares them. If the parent
//	is larger then swap their positions and repeat all the way up
//	the indices as far as necessary.
//********************************************************************
void Heap::makeHeap(int i)
{
	if (i && heap[Parent(i)] > heap[i])
	{
		swap(heap[i], heap[Parent(i)]);
		makeHeap(Parent(i));
	}
}

//********************************************************************
//	Heap::Heapify()
//	Parameters: An integer that is the index to begin at
//	Complexity: O(log n)
//	Effectivly the makeHeap() method in "reverse", it has to find both
//	children instead of just a parent and find the smallest of them
//	all, and put them in proper order. Then calls itself recursivly 
//	to the position the smallest value was found at.
//********************************************************************
void Heap::Heapify(int i)
{
	int l = Left(i);
	int r = Right(i);
	int smallest;

	if (l <= Size() && heap[l] < heap[i])
		smallest = l;
	else
		smallest = i;
	if (r <= Size() && heap[r] < heap[smallest])
		smallest = r;
	if (smallest != i)
	{
		swap(heap[i], heap[smallest]);
		Heapify(smallest);
	}
}

//********************************************************************
//	Heap::printHeap()
//	Parameters: None
//	Complexity: O(n)
//	Loops through the underlying vector and prints the values it holds
//	starting at index one.
//********************************************************************
void Heap::printHeap()
{
	for (int i = 1; i <= Size(); ++i)
	{
		cout << heap[i] << " ";
	}
}
