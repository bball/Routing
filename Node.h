class State;
class Action;

class Node
{
public:
	Node(State* s, Node* parent, Action *action);
	virtual ~Node();
	State *getState() const { return _s; }
	int cost() const { return _cost; }
private:
	State* _s;
	Node *_parent;
	Action *_action;
	int _cost;
};