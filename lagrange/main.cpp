#include <iostream>
#include <lagrange.h>
#include <myfunction.h>

using namespace std;

const double pi = 3.14159265;
const int n = 21;
MyFunction f;

const double a = -1;//0;
const double b = 1;//pi;

const double h = (b - a) / n;

const int size1 = 6;//4;
const int size2 = size1 * 2;

//const map <int, std::pair<double, double>> points1 = {{0, {(pi / 3), f.value(pi / 3)}},
//													  {1, {(pi / 2), f.value(pi / 2)}},
//													  {2, {(4 * pi / 5), f.value(4 * pi / 5)}},
//													  {3, {pi, f.value(pi)}}};

//const map <int, std::pair<double, double>> points2 = {{0, {0, f.value(0)}},
//													  {1, {(pi / 6), f.value(pi / 6)}},
//													  {2, {(pi / 3), f.value(pi / 3)}},
//													  {3, {pi / 2, f.value(pi / 2)}}};

//const map <int, std::pair<double, double>> points3 = {{0, {pi / 2, f.value(pi / 2)}},
//													  {1, {(2 * pi / 3), f.value(2 * pi / 3)}},
//													  {2, {(5 * pi / 6), f.value(5 * pi / 6)}},
//													  {3, {pi, f.value(pi)}}};

//const map <int, std::pair<double, double>> points4 = {{0, {(pi / 4), f.value(pi / 4)}},
//													  {1, {(5 * pi / 12), f.value(5 * pi / 12)}},
//													  {2, {(7 * pi / 12), f.value(7 * pi / 12)}},
//													  {3, {3 * pi / 4, f.value(3 * pi / 4)}}};

//const map <int, std::pair<double, double>> points5 = {{0, {(pi / 3), f.value(pi / 3)}},
//													  {1, {(pi / 2), f.value(pi / 2)}},
//													  {2, {(4 * pi / 5), f.value(4 * pi / 5)}},
//													  {3, {pi, f.value(pi)}},
//													  {4, {(2 * pi / 3), f.value(2 * pi / 3)}},
//													  {5, {(pi / 5), f.value(pi / 5)}},
//													  {6, {0, f.value(0)}},
//													  {7, {(pi / 4), f.value(pi / 4)}}};

const map <int, std::pair<double, double>> points1 = {{0, {(-0.92), f.value(-0.92)}},
													  {1, {(-0.49), f.value(-0.49)}},
													  {2, {(-0.11), f.value(-0.11)}},
													  {3, {0.24, f.value(0.24)}},
													  {4, {0.57, f.value(0.57)}},
													  {5, {0.92, f.value(0.92)}}};

const map <int, std::pair<double, double>> points2 = {{0, {(-1), f.value(-1)}},
													  {1, {(-0.8), f.value(-0.8)}},
													  {2, {(-0.6), f.value(-0.6)}},
													  {3, {-0.4, f.value(-0.4)}},
													  {4, {-0.2, f.value(-0.2)}},
													  {5, {0, f.value(0)}}};

const map <int, std::pair<double, double>> points3 = {{0, {(1), f.value(1)}},
													  {1, {(0.8), f.value(0.8)}},
													  {2, {(0.6), f.value(0.6)}},
													  {3, {0.4, f.value(0.4)}},
													  {4, {0.2, f.value(0.2)}},
													  {5, {0, f.value(0)}}};

const map <int, std::pair<double, double>> points4 = {{0, {(-0.5), f.value(-0.5)}},
													  {1, {(-0.3), f.value(-0.3)}},
													  {2, {(-0.1), f.value(-0.1)}},
													  {3, {0.1, f.value(0.1)}},
													  {4, {0.3, f.value(0.3)}},
													  {5, {0.5, f.value(0.5)}}};

const map <int, std::pair<double, double>> points5 = {{0, {(-0.92), f.value(-0.92)}},
													  {1, {(-0.49), f.value(-0.49)}},
													  {2, {(-0.11), f.value(-0.11)}},
													  {3, {0.24, f.value(0.24)}},
													  {4, {0.57, f.value(0.57)}},
													  {5, {0.92, f.value(0.92)}},
													  {6, {(-0.5), f.value(-0.5)}},
													  {7, {(0.49), f.value(0.49)}},
													  {8, {(0.11), f.value(0.11)}},
													  {9, {-0.24, f.value(-0.24)}},
													  {10, {-0.57, f.value(-0.57)}},
													  {11, {0.5, f.value(0.5)}}};

int main()
{
	Lagrange pol1(points1, size1);
	cout << "case I" << endl;
	for (double i = a; i <= b; i += h)
	{
		cout << i << ' ' << pol1.value(i) << ' ' << f.value(i) << ' ' << fabs(f.value(i) - pol1.value(i)) << ' ' << pol1.error(size1 - 1, i, f) << endl;
	}

	Lagrange pol2(points2, size1);
	cout << endl << "case II" << endl;
	for (double i = a; i <= b; i += h)
	{
		cout << i << ' ' << pol2.value(i) << ' ' << f.value(i) << ' ' << fabs(f.value(i) - pol2.value(i)) << ' ' << pol2.error(size1 - 1, i, f) << endl;
	}

	Lagrange pol3(points3, size1);
	cout << endl << "case III" << endl;
	for (double i = a; i <= b; i += h)
	{
		cout << i << ' ' << pol3.value(i) << ' ' << f.value(i) << ' ' << fabs(f.value(i) - pol3.value(i)) << ' ' << pol3.error(size1 - 1, i, f) << endl;
	}

	Lagrange pol4(points4, size1);
	cout << endl <<"case IV" << endl;
	for (double i = a; i <= b; i += h)
	{
		cout << i << ' ' << pol4.value(i) << ' ' << f.value(i) << ' ' << fabs(f.value(i) - pol4.value(i)) << ' ' << pol4.error(size1 - 1, i, f) << endl;
	}

	Lagrange pol5(points5, size2);
	cout << endl << "case V" << endl;
	for (double i = a; i <= b; i += h)
	{
		cout << i << ' ' << pol5.value(i) << ' ' << f.value(i) << ' ' << fabs(f.value(i) - pol5.value(i)) << ' ' << pol5.error(size2 - 1, i, f) << endl;
	}
}
