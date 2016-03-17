#include "complex.h"

using namespace std;

complex::complex(double re, double im)
{
	this->re = re;
	this->im = im;
}

void complex::setRe(double re)
{
	re = re;
}

void complex::setIm(double im)
{
	im = im;
}

double complex::getRe()
{
	return re;
}

double complex::getIm()
{
	return im;
}

complex complex::operator+(complex x)
{
	return complex(this->getRe() + x.getRe(), this->getIm() + x.getIm());
}

complex complex::operator-(complex x)
{
	return complex(this->getRe() - x.getRe(), this->getIm() - x.getIm());
}

complex complex::operator*(complex x)
{
	return complex(this->getRe() * x.getRe() - this->getIm() * x.getIm(), this->getRe() * x.getIm() + this->getIm() * x.getRe());
}

complex complex::operator=(complex x)
{
	this->im = x.getIm();
	this->re = x.getRe();
}

complex complex::operator=(double x)
{
	this->im = 0;
	this->re = x;
}

complex complex::operator/(complex x)
{
	return complex((this->getRe() * x.getRe() + this->getIm() * x.getIm()) / (x.getIm() * x.getIm() + x.getRe() * x.getRe()),
				   (x.getRe() * this->getIm() - x.getIm() * this->getRe()) / (x.getIm() * x.getIm() + x.getRe() * x.getRe()));
}

void complex::display()
{
	if (re == 0 && im == 0)
	{
		cout << 0;
		return;
	}

	if (re == 0)
	{
		if (im == 1)
		{
			cout << "i";
			return;
		}
		cout << this->getIm() << "i" ;
		return;
	}

	if (im == 0)
	{
		cout << this->getRe();
		return;
	}

	if (im == 1)
	{
		cout << this->getRe() << " + i";
		return;
	}
	cout << this->getRe() << " + " << this->getIm() << "i";
	return;
}
