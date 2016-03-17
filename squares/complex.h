#include <iostream>

class complex
{
public:
	complex(double re, double im);

	void setRe(double re);
	void setIm(double im);
	double getRe();
	double getIm();
	complex operator+(complex x);
	complex operator-(complex x);
	complex operator*(complex x);
	complex operator/(complex x);
	complex operator=(complex x);
	complex operator=(double x);
	void display();

private:
	double re;
	double im;
};
