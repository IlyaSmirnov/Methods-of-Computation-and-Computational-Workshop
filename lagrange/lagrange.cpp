#include "lagrange.h"

Lagrange::Lagrange(map<int, std::pair<double, double>> points, int numberOfPoints)
{
	this->points = points;
	this->numberOfPoints = numberOfPoints;
}

double Lagrange::value(double x)
{
	double sum = 0;

	for (int i = 0; i < numberOfPoints; i++)
	{
		double mult = 1;
		for (int j = 0; j < numberOfPoints; j++)
			if (i != j)
				mult *= (x - points.at(j).first) / (points.at(i).first - points.at(j).first);
		sum += mult * points.at(i).second;
	}

	return sum;
}

int factorial(int n)
{
	if (n < 0)
		return 0;

	return !n ? 1 : n * factorial(n - 1);
}

double Lagrange::error(int degree, double x, MyFunctionF f)
{
	double omega = 1;
	for (int j = 0; j < numberOfPoints; j++)
		omega *= (x - points.at(j).first);

	return fabs(omega) / factorial(degree + 1) * f.maxDerv(degree + 1, x);
}

double Lagrange::error(int degree, double x, MyFunctionG g)
{
	double omega = 1;
	for (int j = 0; j < numberOfPoints; j++)
		omega *= (x - points.at(j).first);

	return fabs(omega) / factorial(degree + 1) * g.maxDerv(degree + 1, x);
}
