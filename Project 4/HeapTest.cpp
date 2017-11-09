#include "Heap.h"
#include <iostream>

using namespace std;

int main()
{
	Heap myheap;

	for (int i = 20; i > 0; --i)
	{
		myheap.Insert(i);
	}
	myheap.printHeap();
	cout << endl;
	while(!myheap.Empty())
	{
		cout << myheap.Extract() << endl;
	}

	return 0;
}
