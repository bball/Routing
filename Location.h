#pragma once

#include <string>
#include <vector>

class Action;

class Location
{
public:
	Location(const std::string& name, const int id) : _id(id), _name(name), _visited(false) {}
	virtual ~Location();
	void addAction(Action *action) { _actions.push_back(action); }
	std::vector<Action*> getActions() const { return _actions; }
	void visited(bool val) { _visited = val; }
	bool isVisited() const { return _visited; }
private:
	//variables
	int _id;
	bool _visited;
	std::string _name;
	std::vector<Action*> _actions;
	//functions
	friend std::ostream& operator<<(std::ostream& os, const Location& obj);
};

