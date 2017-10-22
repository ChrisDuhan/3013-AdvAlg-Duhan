#include <iostream>
#include "ResearchBST.h"

using namespace std;

int main()
{
	//ResearchBST t(TREESIZE);//create an empty tree with _size=0
	int iterations = 100;
	cout << "Data for predecessor delete only " << endl;
	vector<long long>iplData(40, 0);// 40 sample ipl values
	cout << "--------------------------------------------------" << endl;
	for (int ct = 0; ct < iterations; ct++) 
	{//collect data 100 times to average
		if (ct % 2 == 0)cout << ".";// A nice trick to see your program running
		ResearchBST t(TREESIZE);//create an random tree with TREESIZE nodes
		for (int i = 0; i < INSDELPAIRS; i++) 
		{// INSDELPAIRS is 100,000
			if (i % 2500 == 0)
				iplData[i / 2500] += t.IPL();
			t.RandDelInsPair(1);//Im doing a Pdelete every time here
		}
		// t gets destroyed here when it goes out of scope
	}
	cout << endl;
	for (int i = 0; i < 40; i++)// print out the averaged values
		cout << iplData[i] / iterations << endl;
	return 0;
}
