#include <fstream>
#include "File.h"
#include "Points.h"
#include "Interpolation.h"
#include <iostream>
#include <vector>
int main(int argc, char *argv[]) {

	Points p(File::extractCoordinatesFromFile("plasko.txt"));

	p = Interpolation::Lagrange(p, 20, 100);
	p.print();
	return 0;
}