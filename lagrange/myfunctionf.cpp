#include "myfunctionf.h"

MyFunctionF::MyFunctionF()
{
}

double MyFunctionF::value(double x)
{
	return sin(x);
}

double MyFunctionF::maxDerv(int degree, double x)
{
	return 1;
}
