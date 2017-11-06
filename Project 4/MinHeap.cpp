#include "MinHeap.h"
#include <iostream>
#include <vector>

using namespace std;

MinHeap::MinHeap()
{
}


MinHeap::~MinHeap()
{
}

int MinHeap::parent(int i) 
{
	return i >> 1;
}
int MinHeap::left(int i) { return i << 1; }
int MinHeap::right(int i) { return (i << 1) + 1; }

void MinHeap::makeHeap()
{

}

void MinHeap::minHeapify(vector<int> heap, int i)
{
	int l, r;
	l = left(i);
	r = right(i);
	int temp = heap[i];
	int j = 2 * i;
	while (j <= n)
	{
		if (j < n && a[j + 1] < a[j])
			j = j + 1;
		if (temp < a[j])
			break;
		else if (temp >= a[j])
		{
			a[j / 2] = a[j];
			j = 2 * j;
		}
	}
	a[j / 2] = temp;
	return;
}


