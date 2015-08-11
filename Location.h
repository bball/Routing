#include <string>

class Location
{
public:
	Location(const std::string& name, const int id) : _id(id), _name(name) {}
	virtual ~Location() {}
private:
	//variables
	int _id;
	std::string _name;
	//functions
	friend std::ostream& operator<<(std::ostream& os, const Location& obj);
};

std::ostream& operator<<(std::ostream& os, const Location& obj)
{
	os << obj._name << " (" << obj._id << ")" << std::endl;
	return os;
}
