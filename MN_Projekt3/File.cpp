#include "File.h"
#include <fstream>
#include <iostream>
#include <vector>

std::vector<Point> File::extractCoordinatesFromFile(std::string fileName)
{
	std::vector<Point> output;
	std::ifstream file;
	file.open(fileName, std::ifstream::in);
	if (!file) {
		std::cerr << "Unable to open file "<<fileName;
		exit(1);
	}

	auto pos = fileName.find_last_of(".");
	std::string nameWithoutExt = fileName.substr(0, pos);
	std::string extension = fileName.substr(pos);

	std::string fileX = "";
	std::string fileY = "";
	fileX = fileX.append(nameWithoutExt).append("_X").append(extension);
	fileY = fileY.append(nameWithoutExt).append("_Y").append(extension);

	std::ofstream x(fileX), y(fileY);
	//x.precision(20);
	//y.precision(20);

	std::string line;
	Point p;

	while (file >> line) {
		x << std::stod(line.substr(0, line.find(","))) << "\n";
		y << std::stod(line.substr(line.find(",") + 1, line.length())) << "\n";
		
		p.x = std::stod(line.substr(0, line.find(",")));
		p.y = std::stod(line.substr(line.find(",") + 1, line.length()));
		output.push_back(p);
	}


	file.close();
	x.close();
	y.close();

	return output;
}

void File::saveInterpolationResultsToFile(Points p, std::string fileName)
{
	std::string fileNameX="", fileNameY="";
	fileNameX = fileNameX.append(fileName).append("_X.txt");
	fileNameY = fileNameY.append(fileName).append("_Y.txt");
	std::ofstream outputFileX(fileNameX), outputFileY(fileNameY);

	for (auto point : p.points) {
		outputFileX << point.x << "\n";
		outputFileY << point.y << "\n";
	}

	outputFileX.close();
	outputFileY.close();

}
