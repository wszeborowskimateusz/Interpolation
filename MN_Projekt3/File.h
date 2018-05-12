#pragma once
#include <string>
#include <vector>
#include "Points.h"
static class File
{
public:
	//Split one file containing points(x,y) into two files
	static std::vector<Point> extractCoordinatesFromFile(std::string fileName);
};

