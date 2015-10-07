#pragma once

#include <vector>

#include "monomial.h"

using namespace std;

class Polynomial
{
public:
	Polynomial(vector<Monomial> mons);
	double value(double x);
	double derivative(double x);
	double sup();
	double posInf();
	double infim();
	double negSup();

private:
	vector<Monomial> mons;
	double maclaurin();
};
