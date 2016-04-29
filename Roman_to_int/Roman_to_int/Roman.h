#pragma once
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

class Roman
{ 
   public:
		 Roman(const char* ip_ch);
		 Roman(const std::string i_str);
		 explicit Roman(int i);
		 Roman(const Roman& r);
		 Roman& operator=(const Roman& r);
		 
		 int size();

		 int to_int() const;
		 explicit operator int();
		 friend std::ostream& operator<<(std::ostream& os, const Roman& r);
		 Roman operator+(const Roman& r);
		 Roman operator-(const Roman& r);
		 Roman operator/(const Roman& r);
		 Roman operator*(const Roman& r);
		 Roman operator++(int);
		 Roman operator--(int);

	 private:
	  std::string m_number;
};