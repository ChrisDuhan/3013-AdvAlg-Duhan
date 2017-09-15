#include "SLList.h"

//Default constructor
SLList::SLList()
{
	_head = _tail = new Node(0, nullptr);
	_head->_value = 0; //need to init to some value
	_head->_next = new Node(0, nullptr); //trailing node
}

//Destructor
SLList::~SLList()
{
}

//Standard push back, add new item to end of list
void SLList::push_back(int i)
{
	Node * newTail = new Node(i, _tail->_next);
	_tail = _tail->_next = newTail;
	newTail = nullptr;
}

//Adds a node to the front of the list
void SLList::push_front(int i)
{
	Node * front = _head->_next;
	_head->_next = new Node(i, front);
	front = nullptr;
}

//Print the amount of items i starting from the _head node
//or print all items if i = 0
void SLList::print(int i)
{
	Node * tracker = _head->_next;
	if (i != 0)
	{
		for (int inc = 0; inc < i; inc++)
		{
			cout << tracker->_value << " ";
			tracker = tracker->_next;
		}
	}
	else
	{
		while (tracker != _tail->_next)
		{
			cout << tracker->_value << " ";
			tracker = tracker->_next;
		}
	}
}

//Remove the first node in the list
void SLList::pop_front()
{

}

//Returns the value of the first node
int SLList::front()
{

}

//Returns true/false if the list contains values or not
bool SLList::empty()
{

}

//Returns the quantity of nodes in the list
int SLList::size()
{

}
