#pragma once
#include <iostream>
#include <vector>

using namespace std;

class Heap
{
	vector<int> heap;
public:
	Heap();
	Heap(vector<int>);
	~Heap();
	int Size();
	bool Empty();
	void Insert(int);
	int Extract();
	int Parent(int);
	int Left(int);
	int Right(int);
	void makeHeap(int);
	void Heapify(int);
	void printHeap();
};
