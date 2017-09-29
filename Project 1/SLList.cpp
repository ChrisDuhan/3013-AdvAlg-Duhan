//********************************************************************
//      Project #1: Singly linked list class
//      Name: Chris Duhan
//      Class: Advanced Algorithms and Data Structures
//      Instructor: Mr. Richard Simpson
//      Due Date: 09/27/2017
//********************************************************************
//      This program takes a file containing a line of numbers
//		and checks it for duplicated numbers. It takes 
//		non-duplicated numbers and stores them in a new array
//		while ignoring duplicates. The input file must have the
//		quantity of numbers on the line (minus one) as the first
//		number on the line. When telling the program the user 
//		must give the filename as well as the file extension.
//		It is simple enoungh to do without containing it to
//		it's own function so the worst case complexity that
//		the program could experience is O(2n), occuring if there
//		no unique numbers in the list. Otherwise the complexity
//		is O(n).
//
//********************************************************************
#include "SLList.h"

//********************************************************************
//		SLList::SLList()
//		Parameters: None
//		Complexity: O(1)
//		The default constructor, it makes the head node, a trailing
//		node, and the head and tail pointers and points them at the 
//		head node. Nodes are allocated dynamically.
//********************************************************************
SLList::SLList()
{
	_head = _tail = new Node(0, nullptr);
	_head->_value = 0; //need to init to some value
	_head->_next = new Node(0, nullptr); //trailing node
}

//********************************************************************
//		SLList::SLList(const SLList &)
//		Parameters: reference to a constant SLList
//		Complexity: O(n)
//		The copy constructor, it makes the head node, a trailing
//		node, and the head and tail pointers and points them at the 
//		head node. Nodes are allocated dynamically.
//		Then a pointer that follows the list to be copied moves
//		along providing a reference to the value of each node
//		which is given to the push_back() function to avoid making
//		redundant code.
//		The complexity is O(n) where n is the size of the list
//		to be copied.
//********************************************************************
SLList::SLList(const SLList &copy)
{
	Node * follower = copy._head->_next; //next
	_head = _tail = new Node(0, nullptr);
	_head->_value = 0; //need to init to some value
	_head->_next = new Node(0, nullptr); //trailing node

	while (follower->_next != nullptr)
	{
		push_back(follower->_value);
		follower = follower->_next;
	}
}

//********************************************************************
//		SLList::~SLList()
//		Parameters: None
//		Complexity: O(n)
//		The destructor, a pointer takes the place of the head pointer
//		while it moves to the next node, then the node the deleter
//		pointer is pointing at is deleted, as it was allocated
//		dynamically. 
//********************************************************************
SLList::~SLList()
{
	Node * deleter = _head;
	_head = _head->_next;
	delete deleter;
}

//********************************************************************
//		void SLList::push_back(int)
//		Parameters: An intger that is the value to be stored 
//					in the node
//		Complexity: O(1)
//		A standard push_back(), but works with our tail node as well.
//********************************************************************
void SLList::push_back(int i)
{
	Node * newTail = new Node(i, _tail->_next);
	_tail = _tail->_next = newTail;
	_head->_value++;
	newTail = nullptr;
}

//********************************************************************
//		void SLList::push_front(int)
//		Parameters: An intger that is the value to be stored 
//					in the node
//		Complexity: O(1)
//		A standard push_front(), new node right after the head node.
//********************************************************************
void SLList::push_front(int i)
{
	Node * front = _head->_next;
	_head->_next = new Node(i, front);
	_head->_value++;
	front = nullptr;
}

//********************************************************************
//		void SLList::print(int)
//		Parameters: An intger that is the amount of items to be 
//		printed starting after the head node.
//		Complexity: O(n)
//		Prints i items starting after the head node or if i = 0
//		the whole list will be printed.
//********************************************************************
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
	cout << endl;
}


//********************************************************************
//		int SLList::pop_front()
//		Parameters: None, returns an integer
//		Complexity: O(1)
//		Removes the first node in the list after the head node and
//		returns its value.
//********************************************************************
int SLList::pop_front()
{
	if (_head->_value == 0) {
		cout << "No items in list.\n";
		return -1;
	}
	if (_head->_value > 0)
	{
		Node * popper = _head->_next;
		_head->_next = popper->_next;
		delete popper;
		_head->_value--;
		popper = nullptr;
	}
	if (_head->_value == 0) {
		_tail = _head;
	}
		return 0;
	
}

//********************************************************************
//		int SLList::pop_back()
//		Parameters: None, returns an integer
//		Complexity: O(n)
//		Removes the last node in the list before the tail node and
//		returns its value. 
//		I added this one because I felt like it, but I would avoid
//		using it unless nessacary because of its complexity.
//********************************************************************
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

//********************************************************************
//		int SSList::front()
//		Parameters: None, returns an integer
//		Complexity: O(1)
//		Returns the value of the first node in the list after the head
//		node.
//********************************************************************
int SLList::front()
{
	return _head->_next->_value;
}

//********************************************************************
//		bool SSList::empty()
//		Parameters: None, returns a boolean value
//		Complexity: O(1)
//		Truth value is based on contents of the head node.
//********************************************************************
bool SLList::empty()
{
	if (_head->_value != 0)
		return 0;
	return 1;
}

//********************************************************************
//		int SSList::size()
//		Parameters: None, returns an integer
//		Complexity: O(1)
//		Returns the value of the head node in the list as that node
//		is intended to keep track of the number of items in the list.
//********************************************************************
int SLList::size()
{
	return _head->_value;
}

// This code copy/pasted from your website
// This implements the assignment copy operator
// Allows us to do A=B in main where A and B are SLList's
// Also allows the swap(A,B);
SLList & SLList::operator=(const SLList & rhs) {
	if (&rhs != this) {// if not A=A then do a copy
		Node *temp = rhs._head->_next;
		while (_head->_value > 0) this->pop_front();
		for (int i = 0; i < rhs._head->_value; i++)
		{
			(this)->push_back(temp->_value);
			temp = temp->_next;
		}
	}
	return *this;
}
