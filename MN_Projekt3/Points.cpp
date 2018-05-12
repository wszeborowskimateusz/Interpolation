#include "Points.h"



Points::Points(std::vector<Point> input)
{
	for (auto& value : input) {
		points.push_back(value);
	}
}


Points::~Points()
{
}

void Points::print()
{
	for (auto& p : points) {
		std::cout << "x = " << p.x << " y = " << p.y << std::endl;
	}
}
