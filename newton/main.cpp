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

	if (pol.value(a) * pol.value((a + b) / 2) < 0)
	{
		currentAppr = findTheFirstApprox(pol, a, currentAppr);
	}
	else
	{
		currentAppr = findTheFirstApprox(pol, currentAppr, b);
	}

	return currentAppr;
}

void findSolution(Polynomial pol, double a, double b)
{
	double currAppr = findTheFirstApprox(pol, a, b);
	cout << "0 " << currAppr << ' ' << pol.value(currAppr) << endl;
	double tmp = pol.value(currAppr);
	double tmp1 = pol.derivative(currAppr);
	double newAppr = currAppr - pol.value(currAppr) / pol.derivative(currAppr);
	cout << "1 " << newAppr << ' ' << pol.value(newAppr) << endl;

	int k = 2;

	while (fabs(newAppr - currAppr) > eps)
	{
		currAppr = newAppr;
		newAppr = currAppr - pol.value(currAppr) / pol.derivative(currAppr);
		cout << k << ' ' << newAppr << ' ' << pol.value(newAppr) << endl;
		++k;
	}
	cout << endl;
}

void findSolutions(Polynomial pol)
{
	double a = pol.posInf();
	double b = pol.sup();

	double h = (b - a) / 1000;
	for (double i = a; i < b; i = i + h)
	{
		if (pol.value(i) * pol.value(i + h) < 0)
			findSolution(pol, i, i + h);
	}

	a = pol.infim();
	b = pol.negSup();

	h = -(a - b) / 1000;
	for (double i = a; i < b; i = i + h)
	{
		if (pol.value(i) * pol.value(i + h) < 0)
			findSolution(pol, i, i + h);
	}
}

int main()
{
	vector<Monomial> mons;
	//first
	//	mons.push_back(Monomial(2048, 12));
	//	mons.push_back(Monomial(-6144, 10));
	//	mons.push_back(Monomial(6912, 8));
	//	mons.push_back(Monomial(-3584, 6));
	//	mons.push_back(Monomial(840, 4));
	//	mons.push_back(Monomial(-72, 2));
	//	mons.push_back(Monomial(1, 0));

	//second
	//	mons.push_back(Monomial(1, 4));
	//	mons.push_back(Monomial(2, 3));
	//	mons.push_back(Monomial(-25, 2));
	//	mons.push_back(Monomial(-2, 1));
	//	mons.push_back(Monomial(24, 0));
	//third
	mons.push_back(Monomial(1, 3));
	mons.push_back(Monomial(9, 2));
	mons.push_back(Monomial(-6, 1));
	mons.push_back(Monomial(-18, 0));
	Polynomial pol(mons);

	findSolutions(pol);

	return 0;
}

