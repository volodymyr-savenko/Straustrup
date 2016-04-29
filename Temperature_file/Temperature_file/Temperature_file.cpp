// Temperature_file.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <vector>
#include <iostream>
#include <fstream>
#include <algorithm>

struct Temperature
{
	int hour;
	double t_value;
	Temperature(int i_hour, double i_t_value) : hour(i_hour), t_value(i_t_value){}
};

using std::vector;

int _tmain(int argc, _TCHAR* argv[])
{
  vector<Temperature> data;
	std::ofstream ofs("raw_temps.txt");
	int hour;
	double temperature;	
	while (std::cin >> hour >> temperature)
		data.push_back(Temperature(hour, temperature));
	for_each(data.begin(),data.end(), [&ofs](const Temperature& t){
		ofs << t.hour << " " << t.t_value << '\n';
	});
	
	ofs.close();

	data.clear();

	std::ifstream ifs("raw_temps.txt");
	hour = 0;
	temperature = 0;
	while (ifs >> hour >> temperature)
	{ 
		std::cout << hour << "  -  " << temperature << "\n";
		data.push_back(Temperature(hour, temperature));
  }

	std::vector<double> vector_temperatures;

	for_each(data.begin(), data.end(), [&data, &vector_temperatures](Temperature& t){
		vector_temperatures.push_back(t.t_value);
	});

	sort(vector_temperatures.begin(), vector_temperatures.end());

	if (vector_temperatures.size() > 0)
		std::cout << "The median value : " << vector_temperatures[vector_temperatures.size() / 2] << "\n";
	
	size_t count = 0;
	double sum = 0.0;

	for_each(vector_temperatures.begin(), vector_temperatures.end(), [&count, &sum, &vector_temperatures](double& t){
	  count++;
		sum += t;	
	});

	if (count > 0)
		std::cout << "The middle value : " << (sum / count) << "\n";

	return 0;
}

