#pragma once

#include <map>
#include "myfunction.h"

using namespace std;

class Lagrange
{
public:
	Lagrange(map <int, std::pair<double, double>> points, int numberOfPoints);

	double value(double x);
	double error(int degree, double x, MyFunction f);

private:
	int numberOfPoints;
	map <int, std::pair<double, double>> points;
};
