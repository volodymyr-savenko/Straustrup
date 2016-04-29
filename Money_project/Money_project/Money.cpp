#include "stdafx.h"

#include "Money.h"


Money::Money()
{
	bills = 0;
	coins = 0;
}

Money::Money(int i_bills, int i_coins) : bills(i_bills), coins(i_coins)
{
	if (coins > 99)
	{
		bills += coins/100;
		coins = coins % 100;
	}
}

Money::Money(double whole)
{
	bills = static_cast<int>(whole);
	int cents_multiplied_by_hundred = static_cast<int>((whole - bills) * 10000.0000000001);
	int thouthends = cents_multiplied_by_hundred % 100;
	if (thouthends < 50)
		coins = cents_multiplied_by_hundred / 100;
	else
		coins = (cents_multiplied_by_hundred / 100) + 1;
}

Money::Money(const Money& i_proto) : bills(i_proto.bills), coins(i_proto.coins)
{
}

Money& Money::operator=(const Money& i_proto)
{
  bills = i_proto.bills;
	coins = i_proto.coins;  
	return *this;
}

std::ostream& operator<<(std::ostream& os, const Money& mn)
{
	os << mn.bills << "." << mn.coins;
	return os;
}