#include "Interpolation.h"

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
