#include "Points.h"



Points::Points()
{
}

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
	std::cout << "Thera are " << points.size() << " points\n";
	for (auto& p : points) {
		std::cout << "x = " << p.x << " y = " << p.y << std::endl;
	}
}

void Points::reducePointsTo(int number)
{
	std::vector<Point> newPoints;
	int jump = points.size() / number;
	for (int i = 0; i < points.size() && newPoints.size() < number; i+=jump) {
		newPoints.push_back(points[i]);
	}

	points = newPoints;
}
