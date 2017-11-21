//********************************************************************
//	Project #5a: Graph class (Adjacency list)
//	Name: Chris Duhan
//	Class: Advanced Algorithms and Data Structures
//	Instructor: Mr. Richard Simpson
//	Due Date: 11/21/2017
//********************************************************************
//	This program creates a graph based on an adjacency list
//	implemeted by a vector, holding vectors of pairs. The pairs hold
//	what node a particular node is connected to and the weight of the
//	connection between them. Currently a graph is initialized by user
//	input, where the number of nodes the graph starts with must be
//	entered first, then "U" for an undirected graph, or anything else
//	for a directed graph.
//
//********************************************************************

#include "Graph.h"
#include <queue>
#include <iostream>

#define WIP 0;

using namespace std;

//********************************************************************
//	Graph::DFS_Visit()
//	Parameters: An integer for the node that we begin the search at,
//				and the vector that shows the path through the graph,
//				passed to the function by reference as the calling 
//				function created it.
//	Complexity: O(V+E)
//	The function that produces the vector representing the depth-first
//	tree. 
//********************************************************************
void Graph::DFS_Visit(int node, vector<int>& parents)
{
	Color[node] = GREY;
	for (auto child : G[node])
	{
		if (Color[child.first] == WHITE)
		{
			parents[child.first] = node;
			DFS_Visit(child.first, parents);
		}
	}

	Color[node] = BLACK;
}

//********************************************************************
//	Graph::Graph()
//	Parameters: An integer for the number of nodes that will be in the
//				graph and a dtype(directed or undirected)
//	Complexity: O(1)?
//	The default constructor, the graph object is initialized in the 
//	header file but doesn't have anything in it till this method is 
//	used.
//********************************************************************
Graph::Graph(int nodes, dtype type)
{
	G.resize(nodes);
	dir = type;
	int s, n;
	while (cin >> s >> n)	// s is the node to start at, n is the end node
	{
		G[s].push_back(make_pair(n, -1));	// Weights start as -1
		if (dir == UNDIRECTED)	// Undirected needs a conection both ways
			G[n].push_back(make_pair(s, -1));
	}
}

Graph::~Graph()
{
}

//********************************************************************
//	Graph::AddEdge()
//	Parameters: Three integers: the node we begin at, the node we end
//				at and the weight between them (default is zero)
//	Complexity: O(1)
//	For the given start node, add an end node with the given weight, 
//	or the default weight.
//********************************************************************
void Graph::AddEdge(int start, int end, int weight = 0)
{
	G[start].push_back(make_pair(end, weight));
	if (dir == UNDIRECTED)	// Swap start and end
		G[end].push_back(make_pair(start, weight));
}

#if WIP
//********************************************************************
//	Graph::AddEdgeWeight()
//	Parameters: Three integers: the node we begin at, the node we end 
//				at, and the weight of the edge between them 
//	Complexity: O(1)
//	For the given start node, check if it has the given end node and
//	add the weight.
//********************************************************************
void Graph::AddEdgeWeight(int start, int end, int weight)
{
	for (int i = 0; i < G[start].size(); ++i)
		if (G[start][i].first == end)
			G[start][i].second = weight;

	if (dir == UNDIRECTED)	// Swap start and end
		for (int i = 0; i < G[end].size(); ++i)
			if (G[end][i].first == start)
				G[end][i].second = weight;
}
#endif

//********************************************************************
//	Graph::BFS()
//	Parameters: An integer for the node that we begin the search at
//	Complexity: O(V+E)
//	The function that produces the vector representing the breadth-
//	first tree.
//********************************************************************
vector<int> Graph::BFS(int startNode)
{
	Color.resize(G.size());
	for (int i = 0; i < G.size(); ++i)	// Init Color as all white
	{
		Color[i] = WHITE;
	}
	vector<int> parents(G.size(), -1);
	queue<int> Q;
	Q.push(startNode);	// No init list?
	int node;

	while (!Q.empty())
	{
		node = Q.front();	// Read front
		Q.pop();	// Pop front

		for (auto child : G[node])
		{
			if (Color[child.first] == WHITE)
			{
				Color[child.first] = GREY;
				parents[child.first] = node;
				Q.push(child.first);
			}
		}
		Color[node] = BLACK;
	}
	return parents;
}

//********************************************************************
//	Graph::DFS()
//	Parameters: An integer for the node that we begin the search at
//	Complexity: O(V+E)
//	The function that decides how to perform the depth-first search,
//	then calls DFS_Visit() a certain way depending on what node we
//	want to start at.
//********************************************************************
vector<int> Graph::DFS(int start)
{
	Color.resize(G.size());
	for (int i = 0; i < G.size(); ++i)	// Init Color as all white
	{
		Color[i] = WHITE;
	}
	vector<int> parents(G.size(), -1);

	if (start == -1)	// Start from the first item, index 0
	{
		for (int i = 0; i < G.size(); ++i)
		{
			if (Color[i] == WHITE)
			{
				DFS_Visit(i, parents);
			}
		}
	}
	else	// Start from the choosen node, might miss some of the graph
		if (Color[start] == WHITE)
		{
			DFS_Visit(start, parents);
		}

	return parents;
}
