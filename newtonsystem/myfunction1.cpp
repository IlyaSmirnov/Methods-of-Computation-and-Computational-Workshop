#include "myfunction1.h"

MyFunction1::MyFunction1(double a)
{
	this->a = a;
}

double MyFunction1::value(double x, double y)
{
	return tan(a * x + y) - a * x * y - 0.3;
}

double MyFunction1::dervByX(double x, double y)
{
	return a / cos(a * x + y) / cos(a * x + y) - a * y;
}

double MyFunction1::dervByY(double x, double y)
{
	return 1 / cos(a * x + y) / cos(a * x + y) - a * x;
}
