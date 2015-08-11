#include "State.h"
#include "Action.h"
#include "Location.h"

State::State(Location *head) : _cur(head)
{
	_cur->visited(true);
}

State* State::applyAction(Action *action)
{
	if (_cur == action->start())
	{
		State *ns = new State(action->end());
		return ns;
	}
	else return this;
}

std::vector<Action*> State::getActions() const 
{
	return _cur->getActions();
}
