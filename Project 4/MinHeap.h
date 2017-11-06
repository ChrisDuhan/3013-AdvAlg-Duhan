#pragma once
#include <iostream>
#include <vector>
class MinHeap
{
public:
	MinHeap();
	~MinHeap();
	int parent(int);
	int left(int);
	int right(int);
	void makeHeap();
	void minHeapify(vector<int>, int);
};

