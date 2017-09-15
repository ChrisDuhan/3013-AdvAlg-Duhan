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
	L.push_front(111);
	L.print(0);
	return 0;
}
