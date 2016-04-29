// Rational Project.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "Rational.h"

int _tmain(int argc, _TCHAR* argv[])
{
	Rational r1(3, 5);
	Rational r2(234, 12);
	Rational r3(340, 36);
	Rational r4(420, 10);
	Rational r5(652, 126);

	std::cout << r1 << std::endl;
	std::cout << r2 << std::endl;
	std::cout << r3 << std::endl;
	std::cout << r4 << std::endl;
	std::cout << r5 << std::endl;

	std::cout << (r1 + r2) << std::endl;
	std::cout << (r2 / r5) << std::endl;
	std::cout << (r3 - r1) << std::endl;
	std::cout << (r4 * r2) << std::endl;
	std::cout << (r5 - r3) << std::endl;

	return 0;
}

