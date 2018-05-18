#include <fstream>
#include "File.h"
#include "Points.h"
#include "Interpolation.h"
#include <iostream>
#include <vector>
#include <math.h>


int main(int argc, char *argv[]) {

	Points p(File::extractCoordinatesFromFile("stale.txt"));

	p = Interpolation::Spline(p, 10, 10);

	File::saveInterpolationResultsToFile(p, "result");
	p.print();
	
	

	return 0;
}