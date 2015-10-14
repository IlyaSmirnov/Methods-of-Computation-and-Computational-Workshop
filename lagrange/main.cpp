#include <iostream>
#include <lagrange.h>
#include "myfunctionf.h"
#include "myfunctiong.h"

using namespace std;

const double pi = 3.14159265;
const int n = 19;
//case II - the first half, III - the second one, IV - center, V - doubled number

MyFunctionF f;
const double af = 0;
const double bf = pi;
const double hf = (bf - af) / n;
const int size1f = 4;
const int size2f = size1f * 2;

const map <int, std::pair<double, double>> points1f = {{0, {(pi / 3), f.value(pi / 3)}},
													  {1, {(pi / 2), f.value(pi / 2)}},
													  {2, {(4 * pi / 5), f.value(4 * pi / 5)}},
													  {3, {pi, f.value(pi)}}};

const map <int, std::pair<double, double>> points2f = {{0, {0, f.value(0)}},
													  {1, {(pi / 6), f.value(pi / 6)}},
													  {2, {(pi / 3), f.value(pi / 3)}},
													  {3, {pi / 2, f.value(pi / 2)}}};

const map <int, std::pair<double, double>> points3f = {{0, {pi / 2, f.value(pi / 2)}},
													  {1, {(2 * pi / 3), f.value(2 * pi / 3)}},
													  {2, {(5 * pi / 6), f.value(5 * pi / 6)}},
													  {3, {pi, f.value(pi)}}};

const map <int, std::pair<double, double>> points4f = {{0, {(pi / 4), f.value(pi / 4)}},
													  {1, {(5 * pi / 12), f.value(5 * pi / 12)}},
													  {2, {(7 * pi / 12), f.value(7 * pi / 12)}},
													  {3, {3 * pi / 4, f.value(3 * pi / 4)}}};

const map <int, std::pair<double, double>> points5f = {{0, {(pi / 3), f.value(pi / 3)}},
													  {1, {(pi / 2), f.value(pi / 2)}},
													  {2, {(4 * pi / 5), f.value(4 * pi / 5)}},
													  {3, {pi, f.value(pi)}},
													  {4, {(2 * pi / 3), f.value(2 * pi / 3)}},
													  {5, {(pi / 5), f.value(pi / 5)}},
													  {6, {0, f.value(0)}},
													  {7, {(pi / 4), f.value(pi / 4)}}};

MyFunctionG g;
const double ag = -1;
const double bg = 1;
const double hg = (bg - ag) / n;
const int size1g = 6;
const int size2g = size1g * 2;

const map <int, std::pair<double, double>> points1g = {{0, {(-0.92), g.value(-0.92)}},
													  {1, {(-0.49), g.value(-0.49)}},
													  {2, {(-0.11), g.value(-0.11)}},
													  {3, {0.24, g.value(0.24)}},
													  {4, {0.57, g.value(0.57)}},
													  {5, {0.92, g.value(0.92)}}};

const map <int, std::pair<double, double>> points2g = {{0, {(-1), g.value(-1)}},
													  {1, {(-0.8), g.value(-0.8)}},
													  {2, {(-0.6), g.value(-0.6)}},
													  {3, {-0.4, g.value(-0.4)}},
													  {4, {-0.2, g.value(-0.2)}},
													  {5, {0, g.value(0)}}};

const map <int, std::pair<double, double>> points3g = {{0, {(1), g.value(1)}},
													  {1, {(0.8), g.value(0.8)}},
													  {2, {(0.6), g.value(0.6)}},
													  {3, {0.4, g.value(0.4)}},
													  {4, {0.2, g.value(0.2)}},
													  {5, {0, g.value(0)}}};

const map <int, std::pair<double, double>> points4g = {{0, {(-0.5), g.value(-0.5)}},
													  {1, {(-0.3), g.value(-0.3)}},
													  {2, {(-0.1), g.value(-0.1)}},
													  {3, {0.1, g.value(0.1)}},
													  {4, {0.3, g.value(0.3)}},
													  {5, {0.5, g.value(0.5)}}};

const map <int, std::pair<double, double>> points5g = {{0, {(-0.92), g.value(-0.92)}},
													  {1, {(-0.49), g.value(-0.49)}},
													  {2, {(-0.11), g.value(-0.11)}},
													  {3, {0.24, g.value(0.24)}},
													  {4, {0.57, g.value(0.57)}},
													  {5, {0.92, g.value(0.92)}},
													  {6, {(-0.5), g.value(-0.5)}},
													  {7, {(0.49), g.value(0.49)}},
													  {8, {(0.11), g.value(0.11)}},
													  {9, {-0.24, g.value(-0.24)}},
													  {10, {-0.57, g.value(-0.57)}},
													  {11, {0.5, g.value(0.5)}}};

int main()
{
	cout << 'f' << endl << endl;
	Lagrange pol1f(points1f, size1f);
	cout << "case I" << endl;
	for (double i = af; i <= bf; i += hf)
	{
		cout << i << ' ' << pol1f.value(i) << ' ' << f.value(i) << ' ' << fabs(f.value(i) - pol1f.value(i)) << ' ' << pol1f.error(size1f - 1, i, f) << endl;
	}

	Lagrange pol2f(points2f, size1f);
	cout << endl << "case II" << endl;
	for (double i = af; i <= bf; i += hf)
	{
		cout << i << ' ' << pol2f.value(i) << ' ' << f.value(i) << ' ' << fabs(f.value(i) - pol2f.value(i)) << ' ' << pol2f.error(size1f - 1, i, f) << endl;
	}

	Lagrange pol3f(points3f, size1f);
	cout << endl << "case III" << endl;
	for (double i = af; i <= bf; i += hf)
	{
		cout << i << ' ' << pol3f.value(i) << ' ' << f.value(i) << ' ' << fabs(f.value(i) - pol3f.value(i)) << ' ' << pol3f.error(size1f - 1, i, f) << endl;
	}

	Lagrange pol4f(points4f, size1f);
	cout << endl <<"case IV" << endl;
	for (double i = af; i <= bf; i += hf)
	{
		cout << i << ' ' << pol4f.value(i) << ' ' << f.value(i) << ' ' << fabs(f.value(i) - pol4f.value(i)) << ' ' << pol4f.error(size1f - 1, i, f) << endl;
	}

	Lagrange pol5f(points5f, size2f);
	cout << endl << "case V" << endl;
	for (double i = af; i <= bf; i += hf)
	{
		cout << i << ' ' << pol5f.value(i) << ' ' << f.value(i) << ' ' << fabs(f.value(i) - pol5f.value(i)) << ' ' << pol5f.error(size2f - 1, i, f) << endl;
	}

	cout << endl << 'g' << endl << endl;
	Lagrange pol1g(points1g, size1g);
	cout << "case I" << endl;
	for (double i = ag; i <= bg; i += hg)
	{
		cout << i << ' ' << pol1g.value(i) << ' ' << g.value(i) << ' ' << fabs(g.value(i) - pol1g.value(i)) << ' ' << pol1g.error(size1g - 1, i, g) << endl;
	}

	Lagrange pol2g(points2g, size1g);
	cout << endl << "case II" << endl;
	for (double i = ag; i <= bg; i += hg)
	{
		cout << i << ' ' << pol2g.value(i) << ' ' << g.value(i) << ' ' << fabs(g.value(i) - pol2g.value(i)) << ' ' << pol2g.error(size1g - 1, i, g) << endl;
	}

	Lagrange pol3g(points3g, size1g);
	cout << endl << "case III" << endl;
	for (double i = ag; i <= bg; i += hg)
	{
		cout << i << ' ' << pol3g.value(i) << ' ' << g.value(i) << ' ' << fabs(g.value(i) - pol3g.value(i)) << ' ' << pol3g.error(size1g - 1, i, g) << endl;
	}

	Lagrange pol4g(points4g, size1g);
	cout << endl <<"case IV" << endl;
	for (double i = ag; i <= bg; i += hg)
	{
		cout << i << ' ' << pol4g.value(i) << ' ' << g.value(i) << ' ' << fabs(g.value(i) - pol4g.value(i)) << ' ' << pol4g.error(size1g - 1, i, g) << endl;
	}

	Lagrange pol5g(points5g, size2g);
	cout << endl << "case V" << endl;
	for (double i = ag; i <= bg; i += hg)
	{
		cout << i << ' ' << pol5g.value(i) << ' ' << g.value(i) << ' ' << fabs(g.value(i) - pol5g.value(i)) << ' ' << pol5g.error(size2g - 1, i, g) << endl;
	}
}
