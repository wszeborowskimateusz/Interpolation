#include "File.h"
#include <fstream>
#include <iostream>
#include <vector>

void File::extractCoordinatesFromFile(std::string fileName)
{
	std::ifstream file;
	file.open(fileName, std::ifstream::in);
	if (!file) {
		std::cerr << "Unable to open file "<<fileName;
		exit(1);
	}

	std::vector<double> X;
	std::vector<double> Y;

	std::string line;

	while (file >> line) {
		X.push_back(std::stod(line.substr(0, line.find(","))));
		Y.push_back(std::stod(line.substr(line.find(",") + 1, line.length())));
	}


	auto pos = fileName.find_last_of(".");
	std::string nameWithoutExt = fileName.substr(0, pos);
	std::string extension = fileName.substr(pos);

	std::string fileX = "";
	std::string fileY = "";
	fileX = fileX.append(nameWithoutExt).append("_X").append(extension);
	fileY = fileY.append(nameWithoutExt).append("_Y").append(extension);

	std::ofstream x(fileX), y(fileY);
	for (auto& xValue : X) {
		x.precision(20);
		x << xValue << "\n";
	}

	for (auto& yValue : Y) {
		y.precision(20);
		y << yValue << "\n";
	}

	file.close();
	x.close();
	y.close();

}
