#pragma once
#include <vector>
class ResearchBST
{
	struct treeNode;
	typedef treeNode* TreeNodeptr;
	std::vector <int> valueList;// holds the values presently in the tree. Normally not in a tree
	int _size;//number of values in tree and in vector;
	struct treeNode {
		int _value;
		TreeNodeptr _left;
		TreeNodeptr _right;
		treeNode(int key) : _value(key), _left(nullptr), _right(nullptr) {}
	};
	TreeNodeptr _root;
	void insertAux(TreeNodeptr &, const int &);//1-1
	void inOrder(TreeNodeptr tree);//2-1
	void SdeleteAux(TreeNodeptr &, int);//3-1
	void PdeleteAux(TreeNodeptr &, int);//5
	int  iplAux(TreeNodeptr &, int);// 7
	void destroyTree(TreeNodeptr & tree);//4-1
public:
	ResearchBST(int);//1-3, constructs tree with random nodes. It calls insert() multiple times
	~ResearchBST();//4-2 ,Calls DestroyTree()
	void Insert(int value);//1-2, Inserts new node,adds it to the vector and increments _size
	void InOrder();//2-2
	void Sdelete(int);//3-2, successor delete from tree, does not modify size or vector
	void Pdelete(int); //5, predecessor delete from tree, does not modify size or vector 
	
	// The following performs an deletion/insertion pair randomly 
	// Randomly selects value in vector , deletes it from tree and 
	// inserts a new random value into vector and tree. Uses either Sdelete(1) or Pdelete(0)
	void RandDelInsPair(int dType);//6
	int IPL(); //7, Calls iplAux() to return the internal path length. Will discuss in class
};

