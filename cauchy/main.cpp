#include <iostream>
#include <cmath>

using namespace std;

const int n = 10;
const double par = 1;
const double a = 0;
const double b = 1;
const double h = (b - a) / n;
const double h1 = h;
const double h2 = h / 2;
const double h3 = 2 * h;
const double y_0 = 1;

double f(double x, double y)
{
	return x * y * y * y / par - y;
}

double fDerX(double x, double y)
{
	return y * y * y / par;
}

double fDerY(double x, double y)
{
	return 3 * x  * y * y / par - 1;
}

double error(double M4, double M3, double h, double xk, double x0)
{
	return M4 / 2 / M3 * h * exp(M3 * (xk - x0));
}

double euler(double h, double xk, double yk)
{
	return yk + h * f(xk, yk);
}

double adams(int k, double yk, double eta[n + 1], double deta[n], double d2eta[n - 1], double d3eta[n - 2], double d4eta[n - 3])
{
	return yk + eta[k] + deta[k - 1] / 2 + 5 * d2eta[k - 2] / 12 + 3 * d3eta[k - 3] / 8 + 251 * d4eta[k - 4] / 720;
}

double rungeKutta(double h, double xk, double yk)
{
	double k1 = h * f(xk, yk);
	double k2 = h * f(xk + h / 2, yk + k1 / 2);
	double k3 = h * f(xk + h / 2, yk + k2 / 2);
	double k4 = h * f(xk + h, yk + k3);
	return yk + (k1 + 2 * k2 + 2 * k3 + k4) / 6;
}

int main()
{
	double x[n + 1] = {0, 0.1, 0.2, 0.3, 0.4, 0.5, 0.6, 0.7, 0.8, 0.9, 1};
	double y[n + 1];
	y[0] = y_0;
	for (int i = 1; i < n + 1; i++)
	{
		y[i] = rungeKutta(h, x[i - 1], y[i - 1]);
	}

	cout << "Adams" << endl;
	double eta[n + 1];
	double deta[n];
	double d2eta[n - 1];
	double d3eta[n - 2];
	double d4eta[n - 3];

	for (int i = 0; i < n + 1; i++)
	{
		eta[i] = h * f(x[i], y[i]);
	}

	for (int i = 0; i < n; i++)
	{
		deta[i] = eta[i + 1] - eta[i];
	}

	for (int i = 0; i < n - 1; i++)
	{
		d2eta[i] = deta[i + 1] - deta[i];
	}

	for (int i = 0; i < n - 2; i++)
	{
		d3eta[i] = d2eta[i + 1] - d2eta[i];
	}

	for (int i = 0; i < n - 3; i++)
	{
		d4eta[i] = d3eta[i + 1] - d3eta[i];
	}

	int k = 4;
	while(k < n + 1)
	{
		y[k + 1] = adams(k, y[k], eta, deta, d2eta, d3eta, d4eta);
		k++;
	}

	cout << "xk         yk         eta         deta         d2eta         d3eta         d4eta" << endl;
	for (int i = 0; i < n - 3; i++)
	{
		cout << x[i] << "   " << y[i] << "   " << eta[i] << "   " << deta[i] << "   " << d2eta[i] << "   " << d3eta[i] << "   " << d4eta[i] << endl;
	}

	cout << x[n - 3] << "   " << y[n - 3] << "   " << eta[n - 3] << "   " << deta[n - 3] << "   " << d2eta[n - 3] << "   " << d3eta[n - 3] << endl;
	cout << x[n - 2] << "   " << y[n - 2] << "   " << eta[n - 2] << "   " << deta[n - 2] << "   " << d2eta[n - 2] << endl;
	cout << x[n - 1] << "   " << y[n - 1] << "   " << eta[n - 1] << "   " << deta[n - 1] << endl;
	cout << x[n] << "   " << y[n] << "   " << eta[n] << endl;

	cout << endl << "euler" << endl;

	double M1 = fabs(f(0, 0));
	double M2 = fabs(fDerX(0, 0));
	double M3 = fabs(fDerY(0, 0));
	for(double i = a; i <= b; i += h2)
		for(double j = a; j <= b; j += h2)
		{
			double tmp = fabs(f(i, j));
			if (tmp > M1)
				M1 = tmp;

			tmp = fabs(fDerX(i, j));
			if (tmp > M2)
				M2 = tmp;

			tmp = fabs(fDerY(i, j));
			if (tmp > M3)
				M3 = tmp;
		}

	double M4 = M1 * M3 + M2;
	cout << "h1" << endl;
	double yk = y_0;

	cout << "xk      yk      error         theoretical error" << endl;
	k = 0;
	cout << "0       " << yk << "           " << fabs(yk - y[k]) << "            " << fabs(error(M4, M3, h1, x[k], x[0])) << endl;

	for (double i = a + h1; i <= b; i += h1)
	{
		double yk1 = euler(h1, i - h1, yk);
		cout << i << "     " << yk1 << "   " << fabs(yk1 - y[k + 1]) << "             " << fabs(error(M4, M3, h1, x[k + 1], x[0])) << endl;
		yk = yk1;
		k++;
	}

	cout << endl << "h2" << endl;
	yk = y_0;
	k = 0;
	cout << "xk      yk       error       theoretical error" << endl;
	cout << "0       " << yk << "          " << fabs(yk - y[k]) << "                    " << fabs(error(M4, M3, h2, x[0], x[0])) << endl;
	int tmp = 1;
	for (double i = a + h2; i <= b; i += h2)
	{
		if (tmp % 2 == 0)
		{
			double yk1 = euler(h2, i - h2, yk);
			cout << i << "     " << yk1 << "   " << fabs(yk1 - y[k + 1]) << "            " << fabs(error(M4, M3, h2, i, x[0])) << endl;
			yk = yk1;
			k++;
		}
		else
		{
			double yk1 = euler(h2, i - h2, yk);
			cout << i << "     " << yk1 << "                   "  << "     " << fabs(error(M4, M3, h2, i, x[0])) << endl;
			yk = yk1;
		}
		tmp++;
	}
	double yk1 = euler(h2, b - h2, yk);
	cout << b << "     " << yk1 << "   " << fabs(yk1 - y[k + 1]) << "            " << fabs(error(M4, M3, h2, x[n], x[0])) << endl;

	cout << endl << "h3" << endl;
	yk = y_0;
	k = 0;
	cout << "xk      yk      error         theoretical error" << endl;
	cout << "0       " << yk << "          " << fabs(yk - y[k]) << "            " << fabs(error(M4, M3, h3, x[0], x[0])) << endl;
	for (double i = a + h3; i <= b; i += h3)
	{	
		double yk1 = euler(h3, i - h3, yk);
		cout << i << "     " << yk1  << "   " << fabs(yk1 - y[k + 2]) << "            " << fabs(error(M4, M3, h3, i, x[0])) << endl;
		yk = yk1;
		k += 2;
	}

	return 0;
}

