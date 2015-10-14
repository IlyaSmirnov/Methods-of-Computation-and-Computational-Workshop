#pragma once

#include <math.h>

class MyFunctionF
{
public:
	MyFunctionF();

	double value(double x);
	double maxDerv(int degree, double x);
};
