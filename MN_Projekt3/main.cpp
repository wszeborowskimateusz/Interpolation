#include <fstream>
#include "File.h"
#include "Points.h"
#include "Interpolation.h"
#include <iostream>
#include <vector>
int main(int argc, char *argv[]) {

	Points p(File::extractCoordinatesFromFile("plasko.txt"));
	std::cout << Interpolation::LagrangeInterpolation(p, 11400.0) << "\n";

	return 0;
}