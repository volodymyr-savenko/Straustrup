// Concatenate_files.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

int _tmain(int argc, _TCHAR* argv[])
{
	std::ifstream ifs1("data1.txt");
	std::ifstream ifs2("data2.txt");
  std::fstream iofs("concatenated_data.txt");
	
	std::string temp_str;
	char temp_chr;
	std::vector<std::string> words_vector; 

	while (ifs1 >> temp_str)
		words_vector.push_back(temp_str);
	ifs1.close();

	while (ifs2 >> temp_str)
		words_vector.push_back(temp_str);
	ifs2.close();

	sort(words_vector.begin(), words_vector.end());

	for_each(words_vector.begin(), words_vector.end(), [&iofs](const std::string& str){
	iofs << str << " ";
	});

	//iofs.close();

	//std::ifstream ifs("concatenated_data.txt");

	while (iofs >> temp_str)
	  std::cout << temp_str << '\n';

	return 0;
}

