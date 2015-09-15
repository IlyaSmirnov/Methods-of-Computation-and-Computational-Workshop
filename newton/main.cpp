#include <iostream>
#include <cstdlib>

#include "polynomial.h"

using namespace std;

double eps = 0.000001;

double findTheFirstApprox(Polynomial pol, double a, double b)
{
	double currentAppr = (a + b) / 2;
	if (fabs(pol.value(currentAppr)) < 0.1)
	{
		return currentAppr;
	}
	else
	{
		if (pol.value(a) * pol.value((a + b) / 2) < 0)
		{
			currentAppr = findTheFirstApprox(pol, a, currentAppr);
		}
		else
		{
			currentAppr = findTheFirstApprox(pol, currentAppr, b);
		}
	}

	return currentAppr;
}

double newton(Polynomial pol, double a, double b)
{
	double firstApprx = findTheFirstApprox(pol, a, b);
	double currentApprx  = firstApprx - pol.value(firstApprx) / pol.derivative(firstApprx);
	double newApprx = currentApprx - pol.value(currentApprx) / pol.derivative(currentApprx);

	while (fabs(currentApprx - newApprx) > eps)
	{
		currentApprx = newApprx;
		newApprx = currentApprx - pol.value(currentApprx) / pol.derivative(currentApprx);
	}

	return newApprx;
}

int main()
{
	Polynomial pol;
	cout << newton(pol, 1.1, 1.5) << endl;

	return 0;
}

