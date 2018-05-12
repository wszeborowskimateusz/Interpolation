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
	Points(std::vector<Point> input);
	~Points();
	void print();
private:
	std::vector<Point> points;
};

