//********************************************************************
//  A solution to the UVa problem 10954 - Add all, using a MinHeap
//	class I wrote.
//	The way it expects you to solve the problem is not made very clear
//	in the instructions.
//********************************************************************
#include "Heap.h"
#include <iostream>

using namespace std;

int main()
{
	int n, num, sum, total;
	cin >> n;							
	while (n != 0)
	{
		Heap myheap;
		for (int i = 0; i < n; ++i)
		{
			cin >> num;
			myheap.Insert(num);
		}
		sum = total = 0;
		//sum = myheap.Extract();

		while (myheap.Size() != 1)
		{
			num = myheap.Extract();
			sum = num + myheap.Extract();

			total += sum; //add weight

			//push the new sum
			myheap.Insert(sum);
			//sum += myheap.Extract();
			//total += sum;
		}
		cout << total << endl;
		cin >> n;
	}
	return 0;
}
