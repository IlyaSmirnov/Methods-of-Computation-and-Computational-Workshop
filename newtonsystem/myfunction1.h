#pragma once

#include <math.h>

class MyFunction1
{
public:
	MyFunction1(double a);

	double value(double x, double y);
	double dervByX(double x, double y);
	double dervByY(double x, double y);

private:
	double a;
};
