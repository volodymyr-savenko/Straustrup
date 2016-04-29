#pragma once
#include <iostream>

class Rational
{
  public:
		Rational(int i, int j);
		Rational(const Rational& proto);
		Rational& operator=(const Rational& proto);

		Rational operator+(const Rational& r_value);
		Rational operator-(const Rational& r_value);
		Rational operator*(const Rational& r_value);
		Rational operator/(const Rational& r_value);
		bool operator==(const Rational& r_value) const;

		operator double();
		friend std::ostream& operator<<(std::ostream& os, const Rational& rtn);

  private:
	  long int numerator;
		long int denominator;
};

