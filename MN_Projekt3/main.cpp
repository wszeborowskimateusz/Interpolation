#include <fstream>
#include "File.h"
#include "Points.h"
#include "Interpolation.h"
#include <iostream>
#include <vector>
#include <math.h>
int main(int argc, char *argv[]) {

	Points p(File::extractCoordinatesFromFile("plasko.txt"));

	p = Interpolation::Spline(p, 20, 100);
	p.print();

	return 0;
}