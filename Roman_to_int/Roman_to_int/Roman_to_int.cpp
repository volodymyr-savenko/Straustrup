// Roman_to_int.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "Roman.h"
#include <iomanip>

int _tmain(int argc, _TCHAR* argv[])
{
	Roman* array_rnumbers[10];
	array_rnumbers[0] = new Roman("LXX");
	array_rnumbers[1] = new Roman("IV");
	array_rnumbers[2] = new Roman("XIII");
	array_rnumbers[3] = new Roman("XCIX");
	array_rnumbers[4] = new Roman("XIX");
	array_rnumbers[5] = new Roman("MCMXCVIII");
	array_rnumbers[6] = new Roman("MCMXCIX");
	array_rnumbers[7] = new Roman("MMVIII");
	array_rnumbers[8] = new Roman("IX");
	array_rnumbers[9] = new Roman("MCMLXXXIV");

	for (int i = 0; i < (sizeof(array_rnumbers) / sizeof(array_rnumbers[0])); ++i)
		std::cout << *(array_rnumbers[i]) << " = " << array_rnumbers[i]->to_int() << '\n';

	Roman roman1("I");
	 
	for (int i = 1; i < 150; i += 3)
	{
		std::cout << roman1 << std::setw(13 - roman1.size()) << " = " << int(roman1) << '\n';
		roman1 = Roman((int)roman1 + i);
	}
	return 0;
}

