#include "Date.h"


Date::Date() : m_day(0), m_month(0), m_year(0) 
{};

Date::Date(int i_day, int i_month, int i_year) : m_day(i_day), m_month(i_month), m_year(i_year)
{
	if ((m_day > 31) || (m_day < 1))
		std::cout << "Wrong day\n";
  if ((m_month > 12) || (m_month < 1))
		std::cout << "Wrong mouth\n";
	if ((m_year > 2200) || (m_year < 0))
		std::cout << "Wrong year\n";


};

Date::Date(const Date& proto) : m_day(proto.m_day), m_month(proto.m_month), m_year(proto.m_year)
{};

Date& Date::operator=(const Date& proto)
{
	m_day = proto.m_day;
	m_month = proto.m_month;
	m_year = proto.m_year;
	return *this;
};

std::ostream& operator<<(std::ostream& os, const Date& i_date)
{
	if (i_date.m_day < 10)
		os << "0";
	os << i_date.m_day << ".";
	if (i_date.m_month < 10)
		os << "0";
	os << i_date.m_month << "." << i_date.m_year;
  return os;
}

 void Date::add_day()
{
	 if (m_day == 31)
	 {
		 m_day = 1;
		 m_month++;
	 }
	 else
	   m_day++;
	 if (m_month == 13)
	 {
		 m_month = 1;
		 m_year++;
	 }
}

Date::~Date()
{};
