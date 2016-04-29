// integers_from_file.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <vector>
#include <iostream>
#include <fstream>
#include <cmath>
#include <string>

int _tmain(int argc, _TCHAR* argv[])
{
	std::ifstream ifs;
	ifs.open("integers_in_mess.txt");

	int sum_int = 0;
	char temp_char;


	while (ifs >> temp_char)
	{
		if (isdigit(temp_char))
		{ 
			std::string number;
			int temp_int = 0;
			number.push_back(temp_char);
			while (ifs.get(temp_char) && isdigit(temp_char))
				number.push_back(temp_char);
			sum_int += stoi(number);
			std::cout << stoi(number) << " ";
		}
  }
	std::cout << " = " << sum_int << "\n";

	return 0;
}

