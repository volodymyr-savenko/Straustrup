#include "stdafx.h"

#include "getwords.h"
#include <fstream>
#include <iostream>
#include <string>

void print_words_from_file(const char* file_name)
{
	std::ifstream ifs(file_name);
	std::string temp_string;
	int i = 1;
	if (!ifs.is_open())
		std::cout << "Error occures while opening file " << file_name << "\n"; 
	while (std::getline(ifs, temp_string, ','))
	{
		std::cout << i << ". " << temp_string << "\n";
		++i;
	}
	ifs.close();
}