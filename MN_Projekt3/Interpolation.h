#pragma once
#include "Points.h"

class Interpolation
{
public:
	//It first reduces number of points and then returns interpolated Points with x difference that equals deltaX
	static Points Lagrange(Points inputPoints, int howManyPointsToUse, double deltaX);

private:
	static double LagrangeInterpolation(Points inputPoints, double inputX);
};

