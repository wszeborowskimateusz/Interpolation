#pragma once
#include <vector>
#include <iostream>

struct Point {
	double x;
	double y;
};

class Points
{
public:
	Points();
	Points(std::vector<Point> input);
	~Points();
	void print();
	std::vector<Point> points;
	void reducePointsTo(int number);
};

