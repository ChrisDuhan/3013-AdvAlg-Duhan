#include <iostream>
#include "SLList.h"
using namespace std;

int main()
{
	SLList L;
	L.push_back(3);
	L.push_back(4);
	L.push_back(5);
	L.push_back(6);
	L.push_back(7);
	L.push_front(111);
	L.print(0);
	cout << L.front();
	L.pop_front();
	L.pop_back();
	L.print(3);
	cout << L.size() << " " << L.empty();
	return 0;
}
