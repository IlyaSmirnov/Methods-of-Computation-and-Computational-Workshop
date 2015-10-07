#pragma once

#include <math.h>

class Monomial
{
public:
	Monomial();
	Monomial(double coef, int degree);
	double value(double x);
	Monomial derivative();
	double getCoef();
	int getDegree();
	void setCoef(double coef);
	void setDegree(double degree);


private:
	int degree;
	double coef;
};
