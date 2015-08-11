#include <iostream>
#include <vector>

#include "Location.h"
#include "Solver.h"

void main()
{
	std::cout << "Hello" << std::endl;
	std::vector<Location*> nodes;
	Location loc("Home", 0);
	Location loc2("L1", 1);
	nodes.push_back(&loc);
	nodes.push_back(&loc2);
	int timegrid[2][2] = 
	{
		{0, 5},
		{3, 0}
	};
	std::cout << loc << std::endl;
	std::cout << loc2 << std::endl;
	Solver<2> solver(nodes, timegrid);
	bool err = solver.solve();
	if (err)
		std::cout << "Error solving!" << std::endl;
	else
	{
		std::cout << "Solve success, result is:" << std::endl;
		std::cout << solver << std::endl;
	}
	char c;
	std::cin >> c;
}