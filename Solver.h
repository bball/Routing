#pragma once

#include <vector>

class Location;
class State;
class Node;

template <int N>
class Solver
{
public:
	Solver(const std::vector<Location*>& locs, const int costs[][N]) : _locs(locs)
	{
		std::copy(&costs[0][0], &costs[0][0] + N * N, &_costs[0][0]);		
	}
	virtual ~Solver();
	//bool solve() { return false; }
	bool solve();
	bool isSolved();
private:
	std::vector<Location*> _locs;
	std::vector<Location*> _visited;
	int _costs[N][N];
	std::vector<Node*> _nodes;
	//functions
	Node *childNode(Node *parent, Action *action);
	template <int M>
	friend std::ostream& operator<<(std::ostream& os, const Solver<M>& obj);
};

#include "Solver.cpp"

