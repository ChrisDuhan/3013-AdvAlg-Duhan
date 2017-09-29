#pragma once
#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

class SLList
{
	struct Node {
		int _value;
		Node * _next;
		Node(int val, Node * node)
		{
			_value = val;
			_next = node;
		}
	};
	Node * _head;
	Node * _tail;

public:
	SLList();
	SLList(const SLList &);
	~SLList();
	void push_back(int i);
	void push_front(int i);
	void print(int i);
	int pop_front();
	int pop_back();
	int front();
	bool empty();
	int size();
	//********************************************************************
	//		SSList::operator=()
	//		Parameters: const reference to a SLList object
	//		Complexity: O(1)
	//		Overloaded compairison operator.
	//********************************************************************
	SLList &operator=(const SLList &);

	friend ostream &operator<<(ostream &output, const SLList &L) {
		Node * t = L._head->_next;
		//int ct = min(L.size(), 10);
		//List size = 21 : 2, 5, 4, 76, 1, 9, 7, 12, 54, 88, ... 23
		output << "List size = " << L._head->_value << " : ";
		if (L._head->_value > 10) {
			for (size_t i = 0; i < 10; i++)
			{
				output << t->_value << ", ";// leaves a space at end.
				t = t->_next;//go to next node
			}
			cout << "... " << L._tail->_value;
		}
		else {
			while (t != L._tail->_next)
			{
				cout << t->_value << ", ";
				t = t->_next;
			}
		}
		return output;
	}
};
