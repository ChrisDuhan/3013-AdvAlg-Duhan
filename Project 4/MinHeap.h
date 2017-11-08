#pragma once
#include <iostream>
#include <vector>
class MinHeap
{
	vector<int> heap;
public:
	MinHeap();
	~MinHeap();
	int Size();
	int Insert(int);
	int Extract();
	int parent(int);
	int left(int);
	int right(int);
	void makeHeap();
	void minHeapify(vector<int>, int);
};

