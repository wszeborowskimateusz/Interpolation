#include <fstream>
#include "File.h"
#include "Points.h"
#include "Interpolation.h"
#include <iostream>
#include <vector>
#include <math.h>


int main(int argc, char *argv[]) {

	/*
	argv[1] - file name
	argv[2] - how many points to use from the file
	argv[3] - delta x
	argv[4] - S for Spline and L for Lagrange
	argv[5] - result file name - without extension
	*/
	if (argc > 5) {
		
		Points p(File::extractCoordinatesFromFile(argv[1]));
		if (!strcmp(argv[4],"S") || !strcmp(argv[4],"L")) {
			if (!strcmp(argv[4],"S"))
				p = Interpolation::Spline(p, std::stoi(argv[2]), std::stoi(argv[3]));
			else if (!strcmp(argv[4],"L"))
				p = Interpolation::Lagrange(p, std::stoi(argv[2]), std::stoi(argv[3]));
			File::saveInterpolationResultsToFile(p, argv[5]);
			p.print();
		}
	}

	return 0;
}