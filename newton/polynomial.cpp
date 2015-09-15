#include "polynomial.h"

using namespace std;

double Polynomial::value(double x)
{
	return (2048 * pow(x, 12) - 6144 * pow(x, 10) + 6912 * pow(x, 8) - 3584 * pow(x, 6) + 840 * pow(x, 4) - 72 * pow(x, 2) + 1);
	//return (pow(x, 4) + 2 * pow(x, 3) - 25 * pow(x, 2) - 2 * x + 24);
	//return (1.5 * pow(x, 2) - sin(x) -  3);
}

double Polynomial::derivative(double x)
{
	return (24576 * pow(x, 11) - 61440 * pow(x, 9) + 55296 * pow(x, 7) - 21504 * pow(x, 5) + 3360 * pow(x, 3) - 144 * x);
	//return (4 * pow(x, 3) + 6 * pow(x, 2) - 50 * x - 2);
	//return (3 * x - cos(x));
}
