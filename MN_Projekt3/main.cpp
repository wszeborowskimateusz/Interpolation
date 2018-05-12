#include <fstream>
#include "File.h"
#include "Points.h"


#include <vector>
int main() {

	Points p(File::extractCoordinatesFromFile("plasko.txt"));

	p.print();


	return 0;
}