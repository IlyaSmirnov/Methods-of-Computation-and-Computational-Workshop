#include <iostream>
#include <cmath>

using namespace std;

//граничные условия
//y'(0) = aplpha * y(0)
//y'(1) = -beta * y(1)
const double alpha = 0.5;
const double beta = 0.7;
const double a = 0;
const double b = 1;
const int n1 = 10;
const int n2 = 100;
const double h1 = (b - a) / n1;
const double h2 = (b - a) / n2;

const double AWave = alpha * sin(a) - cos(a);
const double BWave = beta * sin(b) + cos(b);

double p(double x)
{
	return 1 + 2 * x;
}

double q(double x)
{
	return -log(1 + x);
}

double f(double x)
{
	return x - 1;
}

double xi1(int i)
{
	return a + i * h1;
}

double ai1(int i)
{
	return 1 + h1 / 2 * p(xi1(i));
}

double bi1(int i)
{
	return 2 - h1 * h1 * q(xi1(i));
}

double ci1(int i)
{
	return 1 - h1 / 2 * p(xi1(i));
}

double gi1(int i)
{
	return h1 * h1 * f(xi1(i));
}

double xi2(int i)
{
	return a + i * h2;
}

double ai2(int i)
{
	return 1 + h2 / 2 * p(xi2(i));
}

double bi2(int i)
{
	return 2 - h2 * h2 * q(xi2(i));
}

double ci2(int i)
{
	return 1 - h2 / 2 * p(xi2(i));
}

double gi2(int i)
{
	return h2 * h2 * f(xi2(i));
}

double yWavei(int i)
{
	return sin(xi2(i));
}

double fWave(double x)
{
	return -sin(x) + p(x) * cos(x) + q(x) * sin(x);
}

double gitest(int i)
{
	return h2 * h2 * fWave(xi2(i));
}

int main()
{
	cout << "n = 10" << endl;
	//из граничных условий
	double kappa11 = 1 / (alpha * h1 + 1);
	double nu11 = 0;
	double kappa21 = 1 / (beta * h1 + 1);
	double nu21 = 0;

	double matrix1[n1 + 1][n1 + 2];
	for (int i = 0; i < n1 + 1; i++)
		for (int j = 0; j < n1 + 2; j++)
			matrix1[i][j] = 0;
	matrix1[0][0] = 1;
	matrix1[0][1] = -kappa11;
	matrix1[0][n1 + 1] = nu11;
	matrix1[n1][n1] = 1;
	matrix1[n1][n1 - 1] = -kappa21;
	matrix1[n1][n1 + 1] = nu21;
	for (int i = 1; i < n1; i++)
	{
		matrix1[i][i - 1] = ci1(i);
		matrix1[i][i] = -bi1(i);
		matrix1[i][i + 1] = ai1(i);
		matrix1[i][n1 + 1] = gi1(i);
	}
	for (int i = 0; i < n1 + 1; i++)
	{
		for (int j = 0; j < n1 + 2; j++)
			cout << matrix1[i][j] << ' ';
		cout << endl;
	}
	
	double u1[n1];
	double v1[n1 + 1];
	u1[0] = kappa11;
	v1[0] = nu11;
	cout << "u and v" << endl << u1[0] << ' ' << v1[0] << endl;
	for (int i = 1; i < n1; i++)
	{
		u1[i] = ai1(i) / (bi1(i) - ci1(i) * u1[i - 1]);
		v1[i] = (ci1(i) * v1[i - 1] - gi1(i)) / (bi1(i) - ci1(i) * u1[i - 1]);
	}
	for (int i = 0; i < n1 + 1; i++)
		cout << u1[i] << ' ' << v1[i] << endl;
	v1[n1] = (-kappa21 * v1[n1 - 1] - nu21) / (-1 + kappa21 * u1[n1 - 1]);

	double y1[n1 + 1];
	y1[n1] = v1[n1];
	for (int i = n1 - 1; i > -1; i--)
		y1[i] = u1[i] * y1[i + 1] + v1[i];
	cout << 'y' << endl;
	for (int i = 0; i < n1 + 1; i++)
		cout << y1[i] << endl;

	cout << "n = 100" << endl;
	//из граничных условий
	double kappa12 = 1 / (alpha * h2 + 1);
	double nu12 = 0;
	double kappa22 = 1 / (beta * h2 + 1);
	double nu22 = 0;
	
	double u2[n2];
	double v2[n2 + 1];
	u2[0] = kappa12;
	v2[0] = nu12;
	cout << "u and v" << endl << u2[0] << ' ' << v2[0] << endl;
	for (int i = 1; i < n2; i++)
	{
		u2[i] = ai2(i) / (bi2(i) - ci2(i) * u2[i - 1]);
		v2[i] = (ci2(i) * v2[i - 1] - gi2(i)) / (bi2(i) - ci2(i) * u2[i - 1]);
	}
	for (int i = 0; i < n2; i += 10)
		cout << u2[i] << ' ' << v2[i] << endl;
	v2[n2] = (-kappa22 * v2[n2 - 1] - nu22) / (-1 + kappa22 * u2[n2 - 1]);

	double y2[n2 + 1];
	y2[n2] = v2[n2];
	for (int i = n2 - 1; i > -1; i--)
		y2[i] = u2[i] * y2[i + 1] + v2[i];
	cout << 'y' << endl;
	for (int i = 0; i < n2 + 1; i += 10)
		cout << y2[i] << endl;

	cout << "check" << endl;
	//из граничных условий
	double kappa1test = 1 / (1 + alpha * h2);
	double kappa2test = 1 / (beta * h2 + 1);
	double nu1test = h2 * AWave / (1 + alpha * h2);
	double nu2test = h2 * BWave / (beta * h2 + 1);

	double utest[n2];
	double vtest[n2 + 1];
	utest[0] = kappa1test;
	vtest[0] = nu1test;
	for (int i = 1; i < n2; i++)
	{
		utest[i] = ai2(i) / (bi2(i) - ci2(i) * utest[i - 1]);
		vtest[i] = (ci2(i) * vtest[i - 1] - gitest(i)) / (bi2(i) - ci2(i) * utest[i - 1]);
	}

	vtest[n2] = (-kappa2test * vtest[n2 - 1] - nu2test) / (-1 + kappa2test * utest[n2 - 1]);
	double ytest[n2 + 1];
	ytest[n2] = vtest[n2];
	for (int i = n2 - 1; i > -1; i--)
		ytest[i] = utest[i] * ytest[i + 1] + vtest[i];
	cout << "y ~y" << endl;
	for (int i = 0; i < n2 + 1; i += 10)
		cout << ytest[i] << ' ' << yWavei(i) << endl;
	
	return 0;
}