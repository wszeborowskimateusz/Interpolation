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

Points Interpolation::Lagrange(Points inputPoints, int howManyPointsToUse, double deltaX)
{
	Points output;
	inputPoints.reducePointsTo(howManyPointsToUse);

	double lastXValue = inputPoints.points.back().x;
	Point p;
	if (lastXValue > 0) {
		for (double i = 0; i < lastXValue; i += deltaX) {
			p.x = i;
			p.y = LagrangeInterpolation(inputPoints, i);
			output.points.push_back(p);
		}
	}


	return output;
}
