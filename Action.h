#pragma once

class Location;
class State;

class Action
{
public:
	Action(Location* start, Location* end, int cost) : _start(start), _end(end), _cost(cost) {}
	virtual ~Action() {}
	Location *start() const { return _start; }
	Location *end() const { return _end; }
	int cost() const { return _cost; }
	//State* execute(State* s);
private:
	Location* _start;
	Location* _end;
	int _cost;
};