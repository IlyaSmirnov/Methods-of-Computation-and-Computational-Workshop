#include "polynomial.h"

using namespace std;

Polynomial::Polynomial(vector<Monomial> mons)
{
	this->mons = mons;
}


double Polynomial::value(double x)
{
	double res = 0;
	for (std::vector<Monomial>::iterator i = mons.begin() ; i != mons.end(); ++i)
	  res += (*i).value(x);

	return res;
}

double Polynomial::derivative(double x)
{
	double res = 0;
	for (std::vector<Monomial>::iterator i = mons.begin() ; i != mons.end(); ++i)
	  res += (*i).derivative().value(x);

	return res;
}

double Polynomial::maclaurin()
{
	double max = fabs((*mons.begin()).getCoef());
	for (std::vector<Monomial>::iterator i = mons.begin() ; i != mons.end(); ++i)
	{
		if (fabs((*i).getCoef()) > max)
			max = fabs((*i).getCoef());
	}

	double a0 = (*mons.begin()).getCoef();

	double m = 0;
	for (std::vector<Monomial>::iterator i = mons.begin() ; i != mons.end(); ++i)
	{
		if ((*i).getCoef() < 0)
			m = (*mons.begin()).getDegree() - (*i).getDegree();
	}

	return (1 + pow(max / a0, 1 / m));
}

double Polynomial::sup()
{
	return maclaurin();
}

double Polynomial::posInf()
{
	vector<Monomial> tempMons;
	double max = (*mons.begin()).getDegree();
	if ((*(mons.end() - 1)).getCoef() > 0)
	{
		for (std::vector<Monomial>::iterator i = mons.end() - 1 ; i != mons.begin(); --i)
		{
			tempMons.push_back(Monomial((*i).getCoef(), max - ((*i).getDegree())));
		}
	}
	else
	{
		for (std::vector<Monomial>::iterator i = mons.end() - 1 ; i != mons.begin(); --i)
		{
			tempMons.push_back(Monomial(-(*i).getCoef(), max - ((*i).getDegree())));
		}
	}

	Polynomial tempPol(tempMons);

	return 1 / tempPol.maclaurin();
}

double Polynomial::infim()
{
	vector<Monomial> tempMons;
	if (((*mons.begin()).getDegree()) % 2 == 0)
	{
		for (std::vector<Monomial>::iterator i = mons.begin() ; i != mons.end(); ++i)
		{
			if ((*i).getDegree() % 2 == 0)
				tempMons.push_back(Monomial((*i).getCoef(), ((*i).getDegree())));
			else
			{
				tempMons.push_back(Monomial(-(*i).getCoef(), ((*i).getDegree())));
			}
		}
	}
	else
	{
		for (std::vector<Monomial>::iterator i = mons.begin() ; i != mons.end(); ++i)
		{
			if ((*i).getDegree() % 2 == 0)
				tempMons.push_back(Monomial(-(*i).getCoef(), ((*i).getDegree())));
			else
			{
				tempMons.push_back(Monomial((*i).getCoef(), ((*i).getDegree())));
			}
		}
	}

	Polynomial tempPol(tempMons);

	return -tempPol.maclaurin();
}

double Polynomial::negSup()
{
	vector<Monomial> tempMons;
	double max = (*mons.begin()).getDegree();
	if ((*(mons.end() - 1)).getCoef() > 0)
	{
		for (std::vector<Monomial>::iterator i = mons.end() - 1; i != mons.begin(); --i)
		{
			tempMons.push_back(Monomial((*i).getCoef(), max - ((*i).getDegree())));
		}
	}
	else
	{
		for (std::vector<Monomial>::iterator i = mons.end() - 1 ; i != mons.begin(); --i)
		{
			tempMons.push_back(Monomial(-(*i).getCoef(), max - ((*i).getDegree())));
		}
	}

	if ((*tempMons.begin()).getDegree() % 2 == 0)
	{
		for (std::vector<Monomial>::iterator i = tempMons.begin() ; i != tempMons.end(); ++i)
		{
			if ((*i).getDegree() % 2 != 0)
				(*i).setCoef(-(*i).getCoef());
		}
	}
	else
	{
		for (std::vector<Monomial>::iterator i = tempMons.begin() ; i != tempMons.end(); ++i)
		{
			if ((*i).getDegree() % 2 == 0)
				(*i).setCoef(-(*i).getCoef());
		}
	}

	Polynomial tempPol(tempMons);

	return -1 / tempPol.maclaurin();
}
