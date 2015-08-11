#include "Solver.h"
#include "State.h"
#include "Action.h"
#include "Node.h"

template <int N>
Solver<N>::~Solver()
{
	for (auto it = _nodes.begin(); it != _nodes.end(); it++)
		delete *it;
}

template <int N>
bool Solver<N>::solve()
{
	if (N < 2)
		return true;
	for (unsigned i = 0; i < N; i++)
	{
		for (unsigned j = 0; j < N; j++)
		{
			if (i != j)
			{
				if (_costs[i][j] != -1)
				{
					Action* a = new Action(_locs[i], _locs[j], _costs[i][j]);
					_locs[i]->addAction(a);
				}
			}
		}
	}
	State *s = new State(_locs[0]);
	Node *base = new Node(s, nullptr, nullptr);
	_nodes.push_back(base);
	_visited.push_back(_locs[0]);
	std::vector<Action*> actions = base->getState()->getActions();
	if (actions.empty())
		return true;
	Node *nn = childNode(base, actions[0]);
	_nodes.push_back(nn);
	_visited.push_back(nn->getState()->cur());
	return !isSolved();
}

template <int N>
bool Solver<N>::isSolved()
{
	return _visited.size() == _locs.size();
}

template <int N>
Node *Solver<N>::childNode(Node *parent, Action *action)
{
	State *ns = parent->getState()->applyAction(action);
	return new Node(ns, parent, action);
}

template <int N>
std::ostream& operator<<(std::ostream& os, const Solver<N>& obj)
{
	//if (!obj._nodes.empty())
	//	os << *(obj._nodes.end()--)->getState()/* << ", cost = " << obj._s->cost()*/;
	return os;
}
