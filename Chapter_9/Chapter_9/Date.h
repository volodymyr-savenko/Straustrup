#include <iostream>
#pragma once

class Date
{
  public:
	  Date();
	  Date(int i_day, int i_month, int i_year);
	  Date(const Date& proto);
		Date& operator=(const Date& proto);
		void add_day();
		virtual ~Date();

		friend std::ostream& operator<<(std::ostream& os, const Date& i_date);
		
  private:
	  int m_day;
		int m_month;
		int m_year;
};

