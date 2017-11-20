#pragma once
#include <vector>
using namespace std;
enum dtype { DIRECTED, UNDIRECTED };
enum color { WHITE, BLACK, GREY };
class Graph
{
	// The wt value will be used in a later algorithm.
	vector<vector<pair<int, int>>> G; //Pair < node#, wt >
	vector<color> Color;// Not really required but will reduce parameter passing.
	dtype dir;
	void DFS_Visit(int, vector<int>&);
public:
	Graph(int, dtype); // resizes G to int and sets dir to type.
	~Graph();
	// NOTE: AddEdge loads both edges if dir = UNDIRECTED
	void AddEdge(int, int, int);
	void AddEdgeWeight(int, int, int);
	vector<int> BFS(int);// return the parent vector (ie the BFS tree)
	vector<int> DFS(int);// dito
};
