#include <cmath>
#include "complex.h"

using namespace std;

const int size = 4;
const double a[size][size + 1] = {{1.25, 0.34, 0.01, -1.27, 4.241942},
								  {0.34, -1.68, -2.04, 0.25, -0.030203},
								  {0.01, -2.04, 0.94, 2.45, -7.411342},
								  {-1.27, 0.25, 2.45, 0.85, -6.289385}};

complex sqrt(complex z)
{
	if (z.getRe() > 0)
		return complex(sqrt(z.getRe()), 0);
	if (z.getRe() < 0)
		return complex(0, sqrt(-z.getRe()));
	if (z.getRe() == 0)
	{
		return complex(0, 0);
	}
}

void squares()
{
	cout << "A b" << endl;
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size + 1; j++)
		{
			cout << a[i][j] << ' ';
		}
		cout << endl;
	}

	complex s[size][size + 1] = {{complex(0, 0), complex(0, 0), complex(0, 0), complex(0, 0), complex(0, 0)},
							 {complex(0, 0), complex(0, 0), complex(0, 0), complex(0, 0), complex(0, 0)},
							 {complex(0, 0), complex(0, 0), complex(0, 0), complex(0, 0), complex(0, 0)},
							 {complex(0, 0), complex(0, 0), complex(0, 0), complex(0, 0), complex(0, 0)}};


	for (int i = 0; i < size; i++)
	{
		for (int j = i; j < size; j++)
		{
			if (i == j)
			{
				s[i][i] = a[i][i];
				for (int l = 0; l < i; l++)
				{
					s[i][i] = s[i][i] - s[l][i] * s[l][i];
				}
				s[i][i] = sqrt(s[i][i]);
				continue;
			}
			if (i != j)
			{
				s[i][j] = a[i][j];
				for (int l = 0; l < i; l++)
					s[i][j] = s[i][j] - s[l][i] * s[l][j];
				s[i][j] = s[i][j] / s[i][i];
			}
		}
	}

	cout << "S" << endl;
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			s[i][j].display();
			cout << ' ';
		}
		cout << endl;
	}

	complex sT[size][size + 1] = {{complex(0, 0), complex(0, 0), complex(0, 0), complex(0, 0), complex(0, 0)},
								  {complex(0, 0), complex(0, 0), complex(0, 0), complex(0, 0), complex(0, 0)},
								  {complex(0, 0), complex(0, 0), complex(0, 0), complex(0, 0), complex(0, 0)},
								  {complex(0, 0), complex(0, 0), complex(0, 0), complex(0, 0), complex(0, 0)}};

	for (int i = 0; i < size; i++)
		for (int j = 0; j < size; j++)
		{
			for (int r = 0; r < size; r++)
				sT[i][j] = s[j][i];
		}
	for (int i = 0; i < size; i++)
		sT[i][size] = complex(a[i][size], 0);

	complex check[size][size] = {{complex(0, 0), complex(0, 0), complex(0, 0), complex(0, 0)},
								 {complex(0, 0), complex(0, 0), complex(0, 0), complex(0, 0)},
								 {complex(0, 0), complex(0, 0), complex(0, 0), complex(0, 0)},
								 {complex(0, 0), complex(0, 0), complex(0, 0), complex(0, 0)}};
	for (int i = 0; i < size; i++)
		for (int j = 0; j < size; j++)
		{
			for (int r = 0; r < size; r++)
				check[i][j] = check[i][j] + sT[i][r] * s[r][j];
		}

	cout << "S^TS" << endl;
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			check[i][j].display();
			cout << ' ';
		}
		cout << endl;
	}
	//gauss(sT);

	complex control1[size] = {complex(0, 0), complex(0, 0), complex(0, 0), complex(0, 0)};
	for (int i = 0; i < size; i++)
	{
		control1[i] = sT[i][5];
		for (int j = 0; j < size; j++)
			control1[i] = control1[i] + sT[i][j];
	}

	//straight
	complex y[size] = {complex(0, 0), complex(0, 0), complex(0, 0), complex(0, 0)};
	for (int i = 0; i < size; i++)
	{
		y[i] = sT[i][size];
	}
	for (int k = 1; k < size; k++)
		for (int j = k; j < size; j++)
		{
			complex tmp = sT[j][k - 1] / sT[k - 1][k - 1];
			for (int i = 0; i <= size; i++)
				sT[j][i] = sT[j][i] - tmp * sT[k - 1][i];
			control1[j] = control1[j] - tmp * control1[k - 1];
			y[j] = y[j] - tmp * y[k - 1];
		}

	cout << "y" << endl;
	for (int i = size - 1; i >= 0; i--)
	{
		for (int j = i + 1; j < size; j++)
			y[i] = y[i] - sT[i][j] * y[j];
		y[i] = y[i] / sT[i][i];
	}
	for (int i = 0; i < size; i++)
	{
		y[i].display();
		cout << endl;
	}

	for (int i = 0; i < size; i++)
		s[i][size] = y[i];

	//gauss(s);
	complex control2[size] = {complex(0, 0), complex(0, 0), complex(0, 0), complex(0, 0)};
	for (int i = 0; i < size; i++)
	{
		control2[i] = s[i][5];
		for (int j = 0; j < size; j++)
			control2[i] = control2[i] + s[i][j];
	}

	//straight
	complex x[size] = {complex(0, 0), complex(0, 0), complex(0, 0), complex(0, 0)};
	for (int i = 0; i < size; i++)
	{
		x[i] = s[i][size];
	}
	for (int k = 1; k < size; k++)
		for (int j = k; j < size; j++)
		{
			complex tmp = s[j][k - 1] / s[k - 1][k - 1];
			for (int i = 0; i <= size; i++)
				s[j][i] = s[j][i] - tmp * s[k - 1][i];
			control2[j] = control2[j] - tmp * control2[k - 1];
			x[j] = x[j] - tmp * x[k - 1];
		}

	cout << "x" << endl;
	for (int i = size - 1; i >= 0; i--)
	{
		for (int j = i + 1; j < size; j++)
			x[i] = x[i] - s[i][j] * x[j];
		x[i] = x[i] / s[i][i];
	}
	for (int i = 0; i < size; i++)
	{
		x[i].display();
		cout << endl;
	}
}


int main()
{
	squares();
	return 0;
}

