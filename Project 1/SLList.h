#pragma once
#include <iostream>

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
	~SLList();
	void push_back(int i);
	void push_front(int i);
	void print(int i);
	void pop_front();
	int front();
	bool empty();
	int size();

};
