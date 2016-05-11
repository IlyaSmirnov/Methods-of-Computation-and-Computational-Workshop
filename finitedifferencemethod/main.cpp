#pragma once
#include <iostream>
#include <cmath>

using namespace std;

const double a = 0;
const double b = 1;
const int n1 = 10;
const int n2 = 100;
const double h1 = (b - a) / n1;
const double h2 = (b - a) / n2;
const double tau1 = h1 * h1 / 4;
const double tau2 = h2 * h2 / 4;
const int m = 500;

double psi1(double t)
{
	return exp(-0.25 * t);
}

double psi2(double t)
{
	return exp(-0.25 * t) * cos(0.5);
}

double phi(double x)
{
	return cos(0.5 * x) + (1 - x) * x;
}

double f(double x, double t)
{
	return exp(-t) * (x * x - x + 2) ;
}

double uStar(double x, double t)
{
	return exp(-0.25 * t) * cos(0.5 * x) + exp(-t) * (1 - x) * x;
}

int main()
{
	cout << "u*, tau1" << endl;
	//for (int k = 0; k < m / 50; k ++)
		for (int k = 0; k < m; k += 50)
	{
		for (int i = 0; i <= n1; i++)
			cout << uStar(a + i * h1, k * tau1) << ' ';
		cout << endl;
	}

	cout << "u*, tau2" << endl;
	for (int k = 0; k < m; k += 50)
	{
		for (double i = 0; i <= n2; i += 10)
			cout << uStar(a + i * h2, k * tau2) << ' ';
		cout << endl;
	}

	cout << "явная схема, n = 10" << endl;
	double u[n1 + 1][m];

	for (int i = 0; i <= n1; i++)
		u[i][0] = phi(a + i * h1);

	for (int k = 0; k < m - 1; k++)
	{
		if (k != 0)
		{
			u[0][k] = psi1(k * tau1);
			u[n1][k] = psi2(k * tau1);
		}
		for (int i = 1; i < n1; i++)
			u[i][k + 1] = (tau1 / h1 / h1) * u[i + 1][k] + (1 - 2 * tau1 / h1 / h1) * u[i][k] + (tau1 / h1 / h1) * u[i - 1][k] + tau1 * f(a + i * h1, k * tau1);
	}

	//for (int k = 0; k < m / 50; k++)
	for (int k = 0; k < m; k += 50)
	{
		for (int i = 0; i <= n1; i++)
			cout << u[i][k] << ' ';
		cout << endl;
	}

	cout << "явная схема, n = 100" << endl;
	double un2[n2 + 1][m];

	for (int i = 0; i <= n2; i++)
		un2[i][0] = phi(a + i * h2);

	for (int k = 0; k < m - 1; k++)
	{
		if (k != 0)
		{
			un2[0][k] = psi1(k * tau2);
			un2[n2][k] = psi2(k * tau2);
		}
		for (int i = 1; i < n2; i++)
			un2[i][k + 1] = ((tau2 / h2 / h2) * un2[i + 1][k] + (1 - 2 * tau2 / h2 / h2) * un2[i][k] + (tau2 / h2 / h2) * un2[i - 1][k]) + tau2 * f(a + i * h2, k * tau2);
	}

	for (int k = 0; k < m; k += 50)
	{
		for (int i = 0; i <= n2; i += 10)
			cout << un2[i][k] << ' ';
		cout << endl;
	}

	cout << "неявная, n = 10" << endl;
	double uback1[n1 + 1][m];
	for (int i = 0; i <= n1; i++)
		uback1[i][0] = phi(a + i * h1);
	for (int k = 1; k < m; k++)

	{
		double apr1[n1 + 1];
		double bpr1[n1 + 1];
		double cpr1[n1 + 1];
		double gpr1[n1 + 1];
		apr1[0] = 0;
		bpr1[0] = 1;
		cpr1[0] = 0;
		gpr1[0] = psi1(k * tau1);
		apr1[n1] = 0;
		bpr1[n1] = 1;
		cpr1[n1] = 0;
		gpr1[n1] = -psi2(k * tau1);
		for (int i = 1; i < n1; i++)
		{
			apr1[i] = tau1;
			bpr1[i] = h1 * h1 + 2 * tau1;
			cpr1[i] = tau1;
			gpr1[i] = -h1 * h1 * uback1[i][k - 1] - h1 * h1 * tau1 * f(a + i * h1, tau1 * k);
		}
		double koef1[n1 + 1];
		double koef2[n1 + 1];
		koef1[0] = -apr1[0];
		koef2[0] = gpr1[0];
		for (int i = 1; i < n1 + 1; i++)
		{
			koef1[i] = apr1[i] / (bpr1[i] - cpr1[i] * koef1[i - 1]);
			koef2[i] = (cpr1[i] * koef2[i - 1] - gpr1[i]) / (bpr1[i] - cpr1[i] * koef1[i - 1]);
		}
		uback1[n1][k] = koef2[n1];
		for (int i = n1 - 1; i >= 0; i--)
		{
			uback1[i][k] = koef1[i] * uback1[i + 1][k] + koef2[i];
		}
	}

	//for (int k = 0; k < m / 50; k++)
	for (int k = 0; k < m; k += 50)
	{
		for (int i = 0; i <= n1; i++)
			cout << uback1[i][k] << ' ';
		cout << endl;
	}

	cout << "неявная, n = 100" << endl;
	double uback2[n2 + 1][m];
	for (int i = 0; i <= n2; i++)
		uback2[i][0] = phi(a + i * h2);
	for (int k = 1; k < m; k++)

	{
		double apr2[n2 + 1];
		double bpr2[n2 + 1];
		double cpr2[n2 + 1];
		double gpr2[n2 + 1];
		apr2[0] = 0;
		bpr2[0] = 1;
		cpr2[0] = 0;
		gpr2[0] = psi1(k * tau2);
		apr2[n2] = 0;
		bpr2[n2] = 1;
		cpr2[n2] = 0;
		gpr2[n2] = -psi2(k * tau2);
		for (int i = 1; i < n2; i++)
		{
			apr2[i] = tau2;
			bpr2[i] = h2 * h2 + 2 * tau2;
			cpr2[i] = tau2;
			gpr2[i] = -h2 * h2 * uback2[i][k - 1] - h2 * h2 * tau2 * f(a + i * h2, tau2 * k);
		}
		double koef12[n2 + 1];
		double koef22[n2 + 1];
		koef12[0] = -apr2[0];
		koef22[0] = gpr2[0];
		for (int i = 1; i < n2 + 1; i++)
		{
			koef12[i] = apr2[i] / (bpr2[i] - cpr2[i] * koef12[i - 1]);
			koef22[i] = (cpr2[i] * koef22[i - 1] - gpr2[i]) / (bpr2[i] - cpr2[i] * koef12[i - 1]);
		}
		uback2[n2][k] = koef22[n2];
		for (int i = n2 - 1; i >= 0; i--)
		{
			uback2[i][k] = koef12[i] * uback2[i + 1][k] + koef22[i];
		}
	}

	//for (int k = 0; k < m / 50; k++)
	for (int k = 0; k < m; k += 50)
	{
		for (int i = 0; i <= n2; i += 10)
			cout << uback2[i][k] << ' ';
		cout << endl;
	}

	return 0;
}