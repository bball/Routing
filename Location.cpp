#include "Location.h"
#include "Action.h"

Location::~Location()
{
	for (auto act = _actions.begin(); act != _actions.end(); act++)
		delete *act;
	_actions.clear();
}

std::ostream& operator<<(std::ostream& os, const Location& obj)
{
	os << obj._name << " (" << obj._id << ")";
	return os;
}
