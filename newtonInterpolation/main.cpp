#include <iostream>

using namespace std;

const int n = 11;
const double x[n] = {0, 0.1, 0.2, 0.3, 0.4, 0.5, 0.6, 0.7, 0.8, 0.9, 1};
const double y[n] = {1.614419, 1.656832, 1.694888, 1.728606, 1.758030, 1.783225, 1.804279, 1.821299, 1.834414, 1.843768};
const double x1a = 0.128079;
const double x2a = 0.703418;
const double x3a = 0.530937;
const double h = 0.1;

double forBeginning(double x1, int start, const double x[n], const double y[n], double deltay[n - 1], double delta2y[n - 2], double delta3y[n - 3], double delta4y[n - 4])
{
	double t = (x1 - x[start]) / h;
	return y[start] + t * deltay[start] + t * (t - 1) / 2 * delta2y[start] + t * (t - 1) * (t - 2) / 2 / 3 * delta3y[start] + t * (t - 1) * (t - 2) * (t - 3) / 2 / 3 / 4 * delta4y[start];
}

double forEnd(double x2, int end, const double x[n], const double y[n], double deltay[n - 1], double delta2y[n - 2], double delta3y[n - 3], double delta4y[n - 4])
{
	double t = (x2 - x[end]) / h;
	return y[end] + t * deltay[end - 1] + t * (t + 1) / 2 * delta2y[end - 2] + t * (t + 1) * (t + 2) / 2 / 3 * delta3y[end - 3] + t * (t + 1) * (t + 2) * (t + 3) / 2 / 3 / 4 * delta4y[end - 4];
}

double forMiddle(double x3, int start, const double x[n], const double y[n], double deltay[n - 1], double delta2y[n - 2], double delta3y[n - 3], double delta4y[n - 4])
{
	double t = (x3 - x[start]) / h;
	return y[start] + t * deltay[start] + t * (t - 1) / 2 * delta2y[start - 2] + t * (t - 1) * (t + 1) / 2 / 3 * delta3y[start - 1] + t * (t - 1) * (t - 2) * (t + 1) / 2 / 3 / 4 * delta4y[start - 2];

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

	cout << "f(x1) = " << forBeginning(x1a, 1, x, y, deltay, delta2y, delta3y, delta4y) << endl;
	cout << "f(x2) = " << forEnd(x2a, 8, x, y, deltay, delta2y, delta3y, delta4y) << endl;
	cout << "for middle: f(x3) = " << forMiddle(x3a, 5, x, y, deltay, delta2y, delta3y, delta4y) << endl;
	cout << "for beginning: f(x3) = " << forBeginning(x3a, 5, x, y, deltay, delta2y, delta3y, delta4y) << endl;
	cout << "for end: f(x3) = " << forEnd(x3a, 6, x, y, deltay, delta2y, delta3y, delta4y) << endl;

	return 0;
}

