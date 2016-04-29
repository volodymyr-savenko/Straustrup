// Straustup_chapter_8.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>
#include <iomanip>
#include <climits>
#include <cstdio>
#include <windows.h>
#include <bitset>


using std::vector;
using std::cout;
using std::cin;
using std::string;

template <typename T>
T maxv(const vector<T>& vec);

template <typename T>
struct vec_info
{
  T min;
	T max;
	T average;
	T median;
};

template <typename T>
vec_info<T> info(const vector<T>& vec);

vector<int> number_of_chrachters(vector<string> str_vec);

int minus(const int a);

int _tmain(int argc, _TCHAR* argv[])
{
	vector<int> int_vec = {1, 2, 2, 3, 234, 43, 37, 17, 11, 5, 87, 35, 76, 432, 6, 32, 67, 86, 49};
	cout << maxv<int>(int_vec) << '\n';

	vec_info<int> info_struct;

	info_struct = info<int>(int_vec);
	cout << "max: " << info_struct.max << '\n'
	<< "min: " << info_struct.min << '\n'
	<< "average: " << info_struct.average << '\n'
	<< "median: " << info_struct.median << '\n';

	vector<string> strings {"You0", "tube", "facebook"};
	vector<int> lengths = number_of_chrachters(strings);
	for (auto i : lengths)
		cout << i << "\n";

	cout << minus(10) << '\n';

};

template <typename T>
T maxv(const vector<T>& vec)
{
	T max_value = vec[0];
	for (const T& current : vec)
	{ 
		if (max_value < current)
		  max_value = current;
	}
	return max_value;
}

vector<int> number_of_chrachters(vector<string> str_vec);

template <typename T>
vec_info<T> info(const vector<T>& vec)
{
	T max_value = vec[0];
	T min_value = vec[0];
	T average = vec[0];
	T median = vec[0];
	
	for (const T& current : vec)
	{
		if (max_value < current)
			max_value = current;
	}
	for (const T& current : vec)
	{
		if (min_value > current)
			max_value = current;
	}
	T sum = 0;
	unsigned int i = 0;
	for (const T& current : vec)
	{
		sum += current;
		++i;
	}
	average = sum / i;
	vector<T>  sorted_vector(vec);
	for (int i = 0; i < sorted_vector.size(); ++i)
		for (int j = i + 1; j < sorted_vector.size(); ++j)
			if (sorted_vector[i] < sorted_vector[j])
				std::swap(sorted_vector[i], sorted_vector[j]);
	median = sorted_vector[sorted_vector.size()/2];

	vec_info<T> result;
	result.max = max_value;
	result.min = min_value;
	result.average = average;
	result.median = median;

	return result;
}

vector<int> number_of_chrachters(vector<string> str_vec)
{
  vector<int> lengths;
	for (const string& str : str_vec)
		lengths.push_back(str.size());
	return lengths;
}

int minus(const int a)
{
  ++a;
	return 0 - a;
}