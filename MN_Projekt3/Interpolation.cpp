#include "Interpolation.h"
#include "LinearEquationsSolver.h"
#include <math.h>

double Interpolation::LagrangeInterpolation(Points inputPoints, double inputX)
{
	double result = 0.0;

	for (int i = 0; i < inputPoints.points.size(); i++)
	{
		double temp = inputPoints.points[i].y;
		for (int j = 0; j < inputPoints.points.size(); j++)
		{
			if (j != i)
				temp = temp * (inputX - inputPoints.points[j].x) / double(inputPoints.points[i].x - inputPoints.points[j].x);
		}

		result += temp;
	}

	return result;
}

Matrix Interpolation::SplineInterpolation(Points inputPoints)
{
	int numberOfCoefficients = 4 * (inputPoints.points.size() - 1);
	Matrix coefficients(numberOfCoefficients, numberOfCoefficients);
	Matrix results(numberOfCoefficients, 1);

	double h = inputPoints.points[1].x - inputPoints.points[0].x;
	//TODO generate proper linear equations
	int offset = 0;
	int tmpFirstDerivative = 1;
	int tmpSecondDerivative = 2;
	for (int i = 0; i < numberOfCoefficients; i++) {

		//Results Matrx filling
		if (i == 0)
			results[i][0] = inputPoints.points[i].y;
		else if(i == (numberOfCoefficients / 2) - 1)
			results[i][0] = inputPoints.points.back().y;
		else if (i < numberOfCoefficients / 2 && i%2 != 0) {
			results[i][0] = inputPoints.points[(i / 2) + 1].y;
			results[i + 1][0] = inputPoints.points[(i / 2) + 1].y;
		}
		else if (i >= numberOfCoefficients / 2) {
			results[i][0] = 0;
		}

		for (int j = 0; j < numberOfCoefficients; j++) {

			//Coefficient Matrix filling
			if ((i % 2 == 0) && i < numberOfCoefficients / 2) {
				if (j == 0) coefficients[i][j] = 1;
				else coefficients[i][j] = 0;
			}
			else if (i < numberOfCoefficients / 2) {
				if (j >= offset && j < offset + 4) {
					if (j % 4 == 0)coefficients[i][j] = 1;
					else if (j % 4 == 1)coefficients[i][j] = h;
					else if (j % 4 == 2)coefficients[i][j] = h*h;
					else coefficients[i][j] = h*h*h;
				}
			}
			else if (i == numberOfCoefficients - 2) {
				if (j == 2)coefficients[i][j] = 2;
				else coefficients[i][j] = 0;
			}
			else if (i == numberOfCoefficients - 1) {
				if (j == numberOfCoefficients - 2)coefficients[i][j] = 2;
				else if (j == numberOfCoefficients - 1)coefficients[i][j] = 6 * h;
				else coefficients[i][j] = 0;
			}
			else {
				if (i % 2 == 0) {
					//first derivative
					if (j == tmpFirstDerivative) coefficients[i][j] = 1;
					else if (j == tmpFirstDerivative + 1) coefficients[i][j] = 2 * h;
					else if (j == tmpFirstDerivative + 2) coefficients[i][j] = 3 * h * h;
					else if (j == tmpFirstDerivative + 4) coefficients[i][j] = -1;
					else coefficients[i][j] = 0;
				}
				else {
					//second derivative
					if (j == tmpSecondDerivative)coefficients[i][j] = 2;
					else if (j == tmpSecondDerivative + 1)coefficients[i][j] = 6 * h;
					else if (j == tmpSecondDerivative + 5)coefficients[i][j] = - 2;
					else coefficients[i][j] = 0;
				}
			}
		}
		if (i % 2 == 1) {
			offset += 4;
			if(i >= numberOfCoefficients / 2)
				tmpSecondDerivative += 5;
		}
		else {
			if (i >= numberOfCoefficients / 2)
				tmpFirstDerivative += 4;
		}
	}

	return LinearEquationsSolver::LU_Factorization(coefficients, results);
}

Points Interpolation::Lagrange(Points inputPoints, int howManyPointsToUse, double deltaX)
{
	Points output;
	inputPoints.reducePointsTo(howManyPointsToUse);

	double lastXValue = inputPoints.points.back().x;
	Point p;
	for (double i = 0; i < lastXValue; i += deltaX) {
		p.x = i;
		p.y = LagrangeInterpolation(inputPoints, i);
		output.points.push_back(p);
	}

	return output;
}

Points Interpolation::Spline(Points inputPoints, int howManyPointsToUse, double deltaX)
{
	Points output;
	inputPoints.reducePointsTo(howManyPointsToUse);

	Matrix coefficientMatrix = SplineInterpolation(inputPoints);

	double lastXValue = inputPoints.points.back().x;
	Point p;
	for (double i = 0; i < lastXValue; i += deltaX) {
		p.x = i;
		double result = 0.0;
		// range in what our current x is - assumption - ranges are equal
		int xRange = i / (lastXValue / (howManyPointsToUse - 1));
		for (int j = 0; j < 4; j++) {
			result += coefficientMatrix[4 * xRange + j][0] * pow(i, j);
		}
		p.y = result;
		output.points.push_back(p);
	}

	return output;
}
