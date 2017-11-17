#include "Graph.h"
#include <iostream>

using namespace std;

int main()
{
	int size;
	char type;

	cin >> type >> size;

	if (type == 'U')
		Graph myG(size, UNDIRECTED);
	else
		Graph myG(size, DIRECTED);
	

	return 0;
}
