#pragma once

#include "myfunction1.h"
#include "myfunction2.h"
#include <iostream>

using namespace std;

class NewtonSystem
{
public:
	NewtonSystem();

	void findSolution(MyFunction1 f, MyFunction2 g, double x0, double y0);
};
