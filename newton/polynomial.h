#pragma once

#include <vector>

#include "monomial.h"
#include "tgpart.h"

using namespace std;

class Polynomial
{
public:
	double value(double x);
	double derivative(double x);
};
