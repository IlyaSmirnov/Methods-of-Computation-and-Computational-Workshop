#pragma once

#include <map>
#include "myfunctionf.h"
#include "myfunctiong.h"

using namespace std;

class Lagrange
{
public:
	Lagrange(map <int, std::pair<double, double>> points, int numberOfPoints);

	double value(double x);
	double error(int degree, double x, MyFunctionF f);
	double error(int degree, double x, MyFunctionG g);

private:
	int numberOfPoints;
	map <int, std::pair<double, double>> points;
};
