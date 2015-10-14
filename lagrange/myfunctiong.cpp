#include "myfunctiong.h"

MyFunctionG::MyFunctionG()
{
}

double MyFunctionG::value(double x)
{
	return sin(5 * x) * sin(5 * x);
}

double MyFunctionG::maxDerv(int degree, double x)
{
	if (degree == 0)
		return 5;

	return 5 * pow(10, degree - 1);
}
