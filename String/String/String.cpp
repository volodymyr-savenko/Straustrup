// String.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <string>
#include "my_string.h"
#include <typeinfo>
#include <vector>
#include <algorithm>
#include <memory>

class A
{
  public:
	A(){Print();};
	virtual void Print(){std::cout << "A" << std::endl;};

	virtual ~A(){std::cout << "~A" << std::endl;};
};

class B : public A
{
  public:
	B(){};
	virtual void Print(){std::cout << "B" << std::endl;};
  
	virtual ~B(){ std::cout << "~B" << std::endl; };
};

class More
{
  public:
	  More(int i_x) : m_x(i_x) 
		{};
	  bool operator()(int i){return i > m_x;};

	private:
	  int m_x;
};

int _tmain(int argc, _TCHAR* argv[])
{
  MyString<int> str("Hello");
	
	//str.Print();
	A* p_a;
	B b;

	p_a = &b;

	std::cout << typeid(b).name() << std::endl;
	std::cout << typeid(*p_a).name() << std::endl;



	std::vector<int> a {3, 1, 2, 11, 5, -2, 23, 21, 32};

	typedef std::vector<int>::iterator int_iter;

	for_each (a.begin(), a.end(), [](int& n)
	{
		std::cout << n << std::endl;
	});

	sort(a.begin(), a.end());
	
	for_each(a.begin(), a.end(), [](int& n)
	{
		std::cout << n << std::endl;
	});

	std::cout << std::count_if(a.begin(), a.end(), More(1));

	//B b;
	//system("Pause");
return 0;
}

