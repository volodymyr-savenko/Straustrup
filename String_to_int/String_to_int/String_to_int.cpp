// String_to_int.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <exception>

using std::vector;
using std::cout;
using std::cin;

int P(int i_a, int i_b);
int C(int i_a, int i_b);
int factorial(int i);

int _tmain(int argc, _TCHAR* argv[])
{
	cout << "Enter two numbers : \n";
	int a = 0;
	int b = 0;

	cin >> a >> b;
	cout << "a = " << a << " and b = "<< b << '\n';

	cout << "a! = " << factorial(a) << "\n";
	cout << "b! = " << factorial(b) << "\n";

	try
	{
	cout << "P(" << a << ", " << b << ") = " << P(a, b) << "\n";
	cout << "C(" << a << ", " << b << ") = " << C(a, b) << "\n";
	}
	catch (std::exception& exc)
	{
		cout << exc.what() << '\n';
	}

	cin.get();
	return 0;
}

int P(int i_a, int i_b)
{
	return factorial(i_a) / factorial(i_a - i_b);
}
int C(int i_a, int i_b)
{
	return P(i_a, i_b) / factorial(i_b);
}

int factorial(int i)
{
	if (i < 1) throw std::exception("Argument of int factorial() is lower than 1");
	if (i == 1)
	  return 1;
	else 
	  return (i * factorial(i - 1));
}