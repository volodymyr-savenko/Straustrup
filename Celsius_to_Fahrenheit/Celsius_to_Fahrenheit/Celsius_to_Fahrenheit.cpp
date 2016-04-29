// Celsius_to_Fahrenheit.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <vector>
#include <fstream>
#include <iostream>
#include <algorithm>

struct Temperature_Fahrenheit
{
	int m_hour;
	double m_temperature;
	Temperature_Fahrenheit(int i_hour, double i_temperature) : m_hour(i_hour), m_temperature(i_temperature) {};
};

double Cel_to_Fahr(double celsius);

using std::vector;

int _tmain(int argc, _TCHAR* argv[])
{ 
  int temp_hour;
	double temp_temperature;
	char temp_letter;
	vector<Temperature_Fahrenheit> temperatures_list;

	std::ifstream ifs("data.txt");
  
	while (ifs >> temp_hour >> temp_temperature >> temp_letter)
	{
		temp_letter = toupper(temp_letter);
		if (temp_letter == 'C')
			temperatures_list.push_back(Temperature_Fahrenheit(temp_hour, Cel_to_Fahr(temp_temperature)));
		else
			temperatures_list.push_back(Temperature_Fahrenheit(temp_hour, temp_temperature));
	}

	for_each(temperatures_list.begin(), temperatures_list.end(), [](Temperature_Fahrenheit& tf){
	std::cout << tf.m_hour << " " << tf.m_temperature << "`F\n";
	});

	return 0;
}

double Cel_to_Fahr(double celsius)
{
	return ((celsius * (9 / 5)) + 32);
}