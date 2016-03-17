#include <iostream>
#include <cmath>

using namespace std;

const double eps = 0.000001;
const int size = 3;
const double a[size][size + 1] = {{786.33663, 0.94384311, -2.4277076, -0.13074427},
								  {0.94384311, 597.12888, 0.56484802, -0.9304191},
								  {-2.4277076, 0.56484802, 473.80154, 1.0656642}};

void simple(const double a[size][size + 1])
{
	double x[size] = {0, 0, 0};
	double nextX[size] = {0, 0, 0};
	nextX[0] = a[0][3]  - a[0][1] * x[1] - a[0][2] * x[2];
	nextX[1] = a[1][3]  - a[1][0] * x[0] - a[1][2] * x[2];
	nextX[2] = a[2][3]  - a[2][0] * x[0] - a[2][1] * x[1];
	int k = 1;
	while ((fabs(nextX[0] - x[0]) > eps) || (fabs(nextX[1] - x[1]) > eps)  || (fabs(nextX[2] - x[2]) > eps))
	{
		cout << k << ") " << nextX[0] << ' ' << nextX[1] << ' ' << nextX[2] << endl;
		for (int i = 0; i < size; i++)
			x[i] = nextX[i];
		nextX[0] = a[0][3]  - a[0][1] * x[1] - a[0][2] * x[2];
		nextX[1] = a[1][3]  - a[1][0] * x[0] - a[1][2] * x[2];
		nextX[2] = a[2][3]  - a[2][0] * x[0] - a[2][1] * x[1];
		k++;
	}
}

void nekrasov(const double a[size][size + 1])
{
	double x[size] = {0, 0, 0};
	double nextX[size] = {0, 0, 0};
	nextX[0] = a[0][3]  - a[0][1] * x[1] - a[0][2] * x[2];
	nextX[1] = a[1][3]  - a[1][0] * x[0] - a[1][2] * x[2];
	nextX[2] = a[2][3]  - a[2][0] * x[0] - a[2][1] * x[1];
	int k = 1;
	while ((fabs(nextX[0] - x[0]) > eps) || (fabs(nextX[1] - x[1]) > eps)  || (fabs(nextX[2] - x[2]) > eps))
	{
		cout << k << ") " << nextX[0] << ' ' << nextX[1] << ' ' << nextX[2] << endl;
		for (int i = 0; i < size; i++)
			x[i] = nextX[i];
		nextX[0] = a[0][3]  - a[0][1] * x[1] - a[0][2] * x[2];
		nextX[1] = a[1][3]  - a[1][0] * nextX[0] - a[1][2] * x[2];
		nextX[2] = a[2][3]  - a[2][0] * nextX[0] - a[2][1] * nextX[1];
		k++;
	}
}

int main()
{
	cout << "eps" << endl << eps << endl;
	cout << 'a' << endl;
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size + 1; j++)
			 cout << a[i][j] << ' ';
		 cout << endl;
	}

	double newa[size][size + 1];
	for (int i = 0; i < size; i++)
	{
		double tmp = a[i][i];
		for (int j = 0; j < size + 1; j++)
			newa[i][j] = a[i][j] / tmp;
	}

	cout << "~a" << endl;
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size + 1; j++)
			 cout << newa[i][j] << ' ';
		 cout << endl;
	}

	cout << "simple" << endl;
	simple(newa);
	cout << "nekrasov" << endl;
	nekrasov(newa);

	return 0;
}

