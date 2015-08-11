#pragma once

#include <vector>

class Location;
class Action;

class State
{
public:
	State(Location *head);
	virtual ~State() {}
	//const Location* on(const Location *nc, int cost) { _cost += cost; _cur = nc; return _cur; }
	State* applyAction(Action *action);
	Location* cur() const { return _cur; }
	std::vector<Action*> getActions() const;
private:
	Location *_cur;
};