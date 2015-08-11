#include <vector>

class Location;

template <int N>
class Solver
{
public:
	Solver(const std::vector<Location*>& nodes, const int costs[][N]) : _nodes(nodes)
	{
		std::copy(&costs[0][0], &costs[0][0] + N * N, &_costs[0][0]);
	}
	virtual ~Solver() {}
	bool solve();
private:
	std::vector<Location*> _nodes;
	int _costs[N][N];
};
