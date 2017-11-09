#include "Heap.h"
#include <iostream>
#include <vector>

using namespace std;

Heap::Heap()
{
	heap.push_back(-1); // occupies index 0
}

Heap::Heap(vector<int> input)
{
	heap.push_back(-1); // occupies index 0
	for (int i = 0; i < input.size(); ++i)
	{
		heap.push_back(input[i]);
	}
}


Heap::~Heap()
{

}

int Heap::Size()
{
	return heap.size() - 1;
}

void Heap::Insert(int i)
{
	heap.push_back(i);
}

int Heap::Extract()
{
	int front = heap.front();
	swap(heap[1], heap[heap.size() - 1]);
	heap.pop_back();
	Heapify(1);
	return front;
}

int Heap::Parent(int i)
{
	return (i - 1) >> 1;
}

int Heap::Left(int i)
{
	return (i << 1) + 1;
}

int Heap::Right(int i)
{
	return (i << 1) + 2;
}

void Heap::makeHeap(vector<int> heap)//
{
	//for (i = heap.size() / 2 downto 1)
	//	Heapify(heap, i);
}

void Heap::Heapify(int i)//
{
	int l = Left(i);
	int r = Right(i);
	int smallest;
	
	if (l < Size() && heap[l] < heap[i])
		smallest = l;
	else
		smallest = i;
	if (r < Size() && heap[r] < heap[smallest])
		smallest = r;
	if (smallest != i)
	{
		swap(heap[i], heap[smallest]);
		Heapify(smallest);
	}
}

void Heap::printHeap()
{
	for (int i = 1; i < Size(); ++i)
	{
		cout << heap[i] << " ";
	}
}
