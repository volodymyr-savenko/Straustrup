#pragma once
#include <iostream>

class Money
{
  public:
		Money();
		Money(int bills, int coins);
		Money(double whole);

		Money(const Money& i_proto);
		Money& operator=(const Money& i_proto);
		friend std::ostream& operator<<(std::ostream& os, const Money& mn);


	private:
	  int bills;
		int coins;
};