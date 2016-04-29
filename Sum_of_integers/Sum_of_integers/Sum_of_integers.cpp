// Sum_of_integers.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <fstream>
#include <iostream>
#include <vector>
#include <string>

int _tmain(int argc, _TCHAR* argv[])
{
  std::ifstream ifs;
	ifs.open("File.txt");
	
	int temp = 0;
	int sum = 0;
	if (!ifs)
		std::cout << "No file.\n";
 
	if (!ifs.eof())
	  { 
		ifs >> temp;
	  sum += temp;
		std::cout << temp;
    }

	while (!ifs.eof())
	  {
		ifs >> temp;
		sum += temp;
		std::cout << " + " <<temp;
	  }
	
	std::cout << " = " << sum << std::endl;

	std::ofstream ofs("Data_read_write.txt", std::ios::app);
	ofs << "Hello, world!\n";
	ofs.close();
	
	std::ifstream ifs2("Data_read_write.txt");
		
	std::string str;
	getline(ifs2, str);
	std::cout << str;
	ifs.close();


	std::ofstream ofs2("Data_read_write.txt", std::ios::app);
	ofs2 << "Hello, Vova!\n";
	ofs2.close();

	std::ifstream ifs3("Data_read_write.txt");

	//std::string str;
	getline(ifs3, str);
	std::cout << str;
	ifs3.close();

	return 0;
}

