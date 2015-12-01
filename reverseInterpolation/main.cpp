#include <iostream>
#include <math.h>

using namespace std;

const int n = 11;
const double x[n] = {0, 0.1, 0.2, 0.3, 0.4, 0.5, 0.6, 0.7, 0.8, 0.9, 1};
const double y[n] = {1.614419, 1.656832, 1.694888, 1.728606, 1.758030, 1.783225, 1.804279, 1.821299, 1.834414, 1.843768};
const double ya = 1.692909;
const double eps = 0.0000001;
double h = 0.1;

double fi(int start, double t, double deltay[n - 1], double delta2y[n - 2], double delta3y[n - 3], double delta4y[n - 4])
{

	return (ya - y[start] - t * (t - 1) / 2 * delta2y[start] - t * (t - 1) * (t - 2) / 2 / 3 * delta3y[start] - t * (t - 1) * (t - 2) * (t - 3) / 2 / 3 / 4 * delta4y[start]) / (deltay[start]);
}

double fia(int start, double t, double deltay[n - 1], double delta2y[n - 2], double delta3y[n - 3], double delta4y[n - 4])
{

	return (t * delta2y[start] + delta2y[start] / 2 - t * t * delta3y[start] / 2 + t * delta3y[start] - t * delta3y[start] / 3 - t * t * t * delta4y[start] / 6 + 18 * t * t * delta4y[start] / 24 - 22 * t * delta4y[start] / 24 + 6 * delta4y[start] / 24) / (deltay[start]);
}

int main()
{
	double deltay[n - 1];
	for (int i = 0; i < n - 1; i++)
		deltay[i] = y[i + 1] - y[i];

	double delta2y[n - 2];
	for (int i = 0; i < n - 2; i++)
		delta2y[i] = deltay[i + 1] - deltay[i];

	double delta3y[n - 3];
	for (int i = 0; i < n - 3; i++)
		delta3y[i] = delta2y[i + 1] - delta2y[i];

	double delta4y[n - 4];
	for (int i = 0; i < n - 4; i++)
		delta4y[i] = delta3y[i + 1] - delta3y[i];


	cout << "x  y  deltay  delta2y   delta3y   delta4y" << endl;

	for (int i = 0; i < n - 4; i++)
	{
		cout << x[i] << "  " << y[i] << "  " << deltay[i] << "  " << delta2y[i] << "  " <<  delta3y[i] << "  " << delta4y[i] << endl;
	}

	cout << x[n - 4] << "  " << y[n - 4] << "  " << deltay[n - 4] << "  " << delta2y[n - 4] << "  " <<  delta3y[n - 4] << endl;
	cout << x[n - 3] << "  " << y[n - 3] << "  " << deltay[n - 3] << "  " << delta2y[n - 3] << endl;
	cout << x[n - 2] << "  " << y[n - 2] << "  " << deltay[n - 2] << endl;
	cout << x[n - 1] << "  " << y[n - 1] << endl << endl;

	int start = 1;
	int k = 1;
	double t = 0.01;
	while (fia(start, t, deltay, delta2y, delta3y, delta4y) > 1 && t <= 1)
		t += 0.01;
	double newT = fi(start, t, deltay, delta2y, delta3y, delta4y);
	cout << "k      tk        fi(tk)" << endl;
	while (fabs(newT - t) > eps)
	{
		cout << k << "      " << t << "      " << newT << endl;
		t = newT;
		newT = fi(start, t, deltay, delta2y, delta3y, delta4y);
		k++;
	}

	cout << "x* = " << x[start] + newT * h;

	return 0;
}

