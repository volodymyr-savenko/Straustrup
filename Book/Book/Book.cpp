// Book.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "Book.h"
#include "Patron.h"


int _tmain(int argc, _TCHAR* argv[])
{
  Book bk("  312 -  31  -  4  -  F  ", Book::Genre::Comics);
	cout << bk;

	Patron ptr1;
	Patron ptr2;
	Patron ptr3;

	cout << ptr1.Number() << " " << ptr2.Number() << " " << ptr3.Number() << "\n";


	return 0;
}

