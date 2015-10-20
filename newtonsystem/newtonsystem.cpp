#include "newtonsystem.h"

const double eps = 0.00001;

NewtonSystem::NewtonSystem()
{

}

double delta(MyFunction1 f, MyFunction2 g, double x, double y)
{
	return f.dervByX(x, y) * g.dervByY(x, y) - f.dervByY(x, y) * g.dervByX(x, y);
}

double deltax(MyFunction1 f, MyFunction2 g, double x, double y)
{
	return - f.value(x, y) * g.dervByY(x, y) + g.value(x, y) * f.dervByY(x, y);
}

double deltay(MyFunction1 f, MyFunction2 g, double x, double y)
{
	return - f.dervByX(x, y) * g.value(x, y) + f.value(x, y) * g.dervByX(x, y);
}

void NewtonSystem::findSolution(MyFunction1 f, MyFunction2 g, double x0, double y0)
{
	double k = 2;
	double xk = x0;
	double yk = y0;
	double xk1 = xk + deltax(f, g, xk, yk) / delta(f, g, xk, yk);
	double yk1 = yk + deltay(f, g, xk, yk) / delta(f, g, xk, yk);
	cout << "0  " << xk << "  " << yk << "  " << f.value(xk, yk) << "  " << g.value(xk, yk) << endl;
	cout << "1  " << xk1 << "  " << yk1 << "  " << f.value(xk1, yk1) << "  " << g.value(xk1, yk1) << endl;

	while (fabs(xk1 - xk) > eps && fabs(yk1 - yk) > eps)
	{
		double xtmp = xk1;
		double ytmp = yk1;
		xk1 = xtmp + deltax(f, g, xtmp, ytmp) / delta(f, g, xtmp, ytmp);
		yk1 = ytmp + deltay(f, g, xtmp, ytmp) / delta(f, g, xtmp, ytmp);
		xk = xtmp;
		yk = ytmp;
		cout << k << "  " << xk1 << "  " << yk1 << "  " << f.value(xk1, yk1) << "  " << g.value(xk1, yk1) << endl;
		k++;
	}
}
