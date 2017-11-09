#include <iostream>
#include <vector>

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
