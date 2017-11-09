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
	void Insert(int);
	int Extract();
	int Parent(int);
	int Left(int);
	int Right(int);
	void makeHeap(vector<int>);
	void Heapify(int);
	void printHeap();
};
