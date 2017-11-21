#include "Graph.h"
#include <iostream>

using namespace std;

int main()
{
	int size;
	char type;
	vector<int> BFSparent;
	vector<int> DFSparent;

	cin >> type >> size;

	if (type == 'U')
	{
		Graph myG(size, UNDIRECTED);
		BFSparent = myG.BFS(5);
		DFSparent = myG.DFS(-1);
		for (int i = 0; i < BFSparent.size(); ++i)
		{
			cout << BFSparent[i] << " ";
		}
		cout << endl;
		for (int i = 0; i < DFSparent.size(); ++i)
		{
			cout << DFSparent[i] << " ";
		}
	}
	else
	{
		Graph myG(size, DIRECTED);
		BFSparent = myG.BFS(5);
		DFSparent = myG.DFS(-1);
		for (int i = 0; i < BFSparent.size(); ++i)
		{
			cout << BFSparent[i] << " ";
		}
		cout << endl;
		for (int i = 0; i < DFSparent.size(); ++i)
		{
			cout << DFSparent[i] << " ";
		}
	}

	
	
	

	return 0;
}
