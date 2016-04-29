#include "stdafx.h"
#include "Rational.h"
#include <algorithm>

namespace
{ 
int GreatestCommonDivisor(int i, int j)
{
	if (i < j)
		std::swap(i, j);
	long int k = 0;
	while (j)
	{
	  k = i % j;
		i = j;
		j = k;  
	}
	return i;
}
}

Rational::Rational(int i, int j) : numerator(i), denominator(j)
{
	long int gcd = GreatestCommonDivisor(numerator, denominator);
	numerator /= gcd;
	denominator /= gcd;
	if (denominator < 0)
	{
		denominator = 0 - denominator;
		numerator = 0 - numerator;
	}
};

Rational::Rational(const Rational& proto) : numerator(proto.numerator), denominator(proto.denominator){};

Rational& Rational::operator=(const Rational& proto)
{
  numerator = proto.numerator;
	denominator = proto.denominator;
  return *this;
}

Rational Rational::operator+(const Rational& r_value)
{
	return Rational(numerator * r_value.denominator + r_value.numerator * denominator, denominator * r_value.denominator);
}

Rational Rational::operator-(const Rational& r_value)
{
	return Rational(numerator * r_value.denominator - r_value.numerator * denominator, denominator * r_value.denominator);
}

Rational Rational::operator*(const Rational& r_value)
{
	return Rational(numerator * r_value.numerator, denominator * r_value.denominator);
}

Rational Rational::operator/(const Rational& r_value)
{
	return Rational(numerator * r_value.denominator, denominator * r_value.numerator);
}
bool Rational::operator==(const Rational& r_value) const
{
	if (numerator == r_value.numerator && denominator == r_value.denominator)
	  return true;
	else
	  return false;
}

Rational::operator double()
{
	return (1.0*numerator)/denominator;
}

std::ostream& operator<<(std::ostream& os, const Rational& rtn)
{
	os << rtn.numerator << "/" << rtn.denominator;
	return os;
}
