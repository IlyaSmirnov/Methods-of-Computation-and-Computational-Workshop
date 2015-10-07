#include "monomial.h"

Monomial::Monomial()
{
	this->degree = 0;
	this->coef = 0;
}

Monomial::Monomial(double coef, int degree)
{
	this->degree = degree;
	this->coef = coef;
}

double Monomial::value(double x)
{
	return coef * pow(x, degree);
}


Monomial Monomial::derivative()
{
	if (degree != 0)
		return Monomial(this->getDegree() * this->coef, this->degree - 1);

	return Monomial(0, 0);
}

double Monomial::getCoef()
{
	return this->coef;
}

int Monomial::getDegree()
{
	return this->degree;
}

void Monomial::setCoef(double coef)
{
	this->coef = coef;
}

void Monomial::setDegree(double degree)
{
	this->degree = degree;
}
