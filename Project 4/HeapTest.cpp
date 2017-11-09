/*
int main()
{
	Heap myheap;
	for (int i = 0; i < 100; ++i)
	{
		myheap.Insert(rand() % 100);
	}
	myheap.printHeap();
	cout << endl;
	while(!myheap.Empty())
	{
		cout << myheap.Extract() << endl;
	}
	return 0;
}
*/

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
		sum = myheap.Extract();
		
		while (!myheap.Empty())
		{
			sum += myheap.Extract();
			total += sum;
		}
		cout << total << endl;
		cin >> n;
	}
	return 0;
}
