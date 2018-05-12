#pragma once
#include "Points.h"
#include "Matrix.h"

class Interpolation
{
public:
	//It first reduces number of points and then returns interpolated Points with x difference that equals deltaX
	static Points Lagrange(Points inputPoints, int howManyPointsToUse, double deltaX);

	static Points Spline(Points input, int howManyPointsToUse, double deltaX);

private:
	static double LagrangeInterpolation(Points inputPoints, double inputX);
	static Matrix SplineInterpolation(Points inputPoints);
};

