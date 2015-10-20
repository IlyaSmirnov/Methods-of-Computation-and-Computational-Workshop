#include "myfunction2.h"

MyFunction2::MyFunction2(double k)
{
	this->k = k;
}

double MyFunction2::value(double x, double y)
{
	return x * x + y * y - k;
}

double MyFunction2::dervByX(double x, double y)
{
	return 2 * x;
}

double MyFunction2::dervByY(double x, double y)
{
	return 2 * y;
}
