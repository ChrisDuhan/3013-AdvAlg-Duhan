//********************************************************************
//	Project #5a: Graph class (Adjacency list)
//	Name: Chris Duhan
//	Class: Advanced Algorithms and Data Structures
//	Instructor: Mr. Richard Simpson
//	Due Date: 11/21?/2017
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

using namespace std;

void Graph::DFS_Visit(int, vector<int>&)
{
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
//	Graph::AddNewEdge()
//	Parameters: Two integers: the node we begin at, the node we end at 
//	Complexity: O(1)
//	For the given start node, add an end node with placeholder weight.
//********************************************************************
void Graph::AddNewEdge(int start, int end)
{
	G[start].push_back(make_pair(end, -1));
	if (dir == UNDIRECTED)	// Swap start and end
		G[end].push_back(make_pair(start, -1));
}

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
		if (get<0>(G[start][i]) == end)
			get<1>(G[start][i]) = weight;

	if (dir == UNDIRECTED)	// Swap start and end
		for (int i = 0; i < G[end].size(); ++i)
			if (get<0>(G[end][i]) == start)
				get<1>(G[end][i]) = weight;
}

vector<int> Graph::BFS(int startNode)
{
	vector<color> nodeColor(G.size(), WHITE);
	vector<int> parents;
	queue<int> Q;
	Q.push(startNode);	// No init list?
	int node;

	while (!Q.empty())
	{
		node = Q.front();	// Read front
		Q.pop();	// Pop front

		for (auto child : G[node])
		{
			if (Color[get<1>(child)] == WHITE)
			{
				Color[get<1>(child)] = GREY;
				parents[get<0>(child)] = node;
				Q.push(get<0>(child));
			}
		}
		Color[node] = BLACK;
	}
	return parents;
}

vector<int> Graph::DFS(int)
{
	return vector<int>();
}