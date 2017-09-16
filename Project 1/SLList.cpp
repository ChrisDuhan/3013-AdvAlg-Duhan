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
	Node * deleter = _head;
	_head = _head->_next;
	//delete deleter;

}

//Standard push back, add new item to end of list
void SLList::push_back(int i)
{
	Node * newTail = new Node(i, _tail->_next);
	_tail = _tail->_next = newTail;
	_head->_value++;
	newTail = nullptr;
}

//Adds a node to the front of the list
void SLList::push_front(int i)
{
	Node * front = _head->_next;
	_head->_next = new Node(i, front);
	_head->_value++;
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
int SLList::pop_front()
{
	if (_head->_value = 0)
	{
		Node * popper = _head->_next;
		_head->_next = popper->_next;
		delete popper;
		_head->_value--;
		popper = nullptr;
		return 0;
	}
	else
	{
		cout << "No items in list.\n";
		return 0;
	}
}

//Remove the last item in the list...
//It has n complexity so don't use it much
int SLList::pop_back()
{
	if (_head->_value = 0)
	{
		Node * finder = _head->_next;
		while (finder->_next != _tail)
			finder = finder->_next;
		finder->_next = _tail->_next;
		delete _tail;
		_tail = finder;
		_head->_value--;
		finder = nullptr;
		return 0;
	}
	else
	{
		cout << "No items in list.\n";
		return 0;
	}
	
}
//Returns the value of the first node
int SLList::front()
{
	return _head->_next->_value;
}

//Returns true/false if the list contains values or not
bool SLList::empty()
{
	if (_head->_value != 0)
		return 0;
	return 1;
}

//Returns the quantity of nodes in the list
int SLList::size()
{
	return _head->_value;
}
