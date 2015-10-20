#include "newtonsystem.h"

const double a[6] = {-1.2, -1, -0.8, -0.6, -0.4, 0.2};
const double b[5] = {1.3, 1.5, 1.7, 1.9, 2.1};

pair<double, double> findFirstApproximation(MyFunction1 f, MyFunction2 g)
{
	for (double i = 0; i <= 2; i += 0.001)
	{
		for (double j = 0; j <= 2; j += 0.001)
			if (fabs(f.value(i, j)) < 0.1 && fabs(g.value(i, j)) < 0.1)
				return pair<double, double>(i, j);
	}
}

int main()
{
	int n = 1;
	NewtonSystem newton;
	for (int i = 0; i < 6; i++)
		for (int j = 0; j < 5; j++)
		{
			pair<double, double> firstApprxm = findFirstApproximation(MyFunction1(a[i]), MyFunction2(b[j]));
			cout << n <<  endl;
			cout << "k  xk     yk     f(xk, yk)  g(xk, yk)" << endl;
			MyFunction1 f = MyFunction1(a[i]);
			MyFunction2 g = MyFunction2(b[j]);
			newton.findSolution(f, g, firstApprxm.first, firstApprxm.second);
			n++;
			cout << endl << endl;
		}
}

