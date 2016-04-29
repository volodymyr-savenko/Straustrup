// Money_project.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "Money.h"
using std::cout;


int _tmain(int argc, _TCHAR* argv[])
{
  Money mn1;
	cout << mn1 << std::endl;
	Money mn2(213, 31234);
	cout << mn2 << std::endl;
	Money mn3(213.315);
	cout << mn3 << std::endl;



	return 0;
}

