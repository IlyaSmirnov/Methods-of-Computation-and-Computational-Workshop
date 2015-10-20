#pragma once

class MyFunction2
{
public:
	MyFunction2(double k);

	double value(double x, double y);
	double dervByX(double x, double y);
	double dervByY(double x, double y);

private:
	double k;
};
