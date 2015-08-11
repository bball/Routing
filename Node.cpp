#include "Node.h"
#include "Action.h"

Node::Node(State* s, Node* parent, Action *action) : 
 _s(s)
, _parent(parent)
, _action(action)
{
	if (parent)
		_cost = parent->cost() + action->cost();
	else
		_cost = 0;
}

Node::~Node()
{
	delete _s;
}