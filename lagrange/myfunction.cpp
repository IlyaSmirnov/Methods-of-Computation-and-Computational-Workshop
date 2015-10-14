#include "myfunction.h"

MyFunction::MyFunction()
{

}

double MyFunction::value(double x)
{
	return sin(5 * x) * sin(5 * x);
	//return sin(x);
}

double MyFunction::maxDerv(int degree, double x)
{
	if (degree == 0)
		return 5;

	return 5 * pow(10, degree - 1);
}
