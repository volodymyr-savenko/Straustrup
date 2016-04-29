#pragma once
#include <string>;
#include <vector>
#include <iostream>

using std::string;
using std::cin;
using std::cout;

class Book
{ 
  public:
		enum class Genre {Comics, Fanasy, SciFi, NoGenre};
		Book()
		  { 
			number.x1 = 0;
			number.x2 = 0;
			number.x3 = 0;
			number.ch = 'x';
			m_genre = Genre::NoGenre;
		  };

		Book(string str, Genre i_genre);

		friend std::ostream& operator<<(std::ostream& os, const Book& i_book);

  private:
	  struct ISBN
	  {
	   int x1;
	   int x2;
	   int x3;
	   char ch;
	   };
		ISBN number;
		Genre m_genre;
		std::vector<char*> genres;
};

std::ostream& operator<<(std::ostream& os, const Book& i_book)
{
	os << i_book.number.x1 << "-" << i_book.number.x2 << "-" << i_book.number.x3 << "-" << i_book.number.ch << std::endl;
	os << i_book.genres[(int)i_book.m_genre] << '\n';
	return os;
}

Book::Book(string str, Genre i_genre)
{ 
  genres = {"Comics", "Fanasy", "SciFi", "NoGenre"};
	string temp_x1;
	int i = 0;
	while ((str[i] != '-') && (i < str.size()))
		{
		temp_x1.push_back(str[i]);
		++i;
		}
	number.x1 = atoi(temp_x1.c_str());
	
	i++;
	string temp_x2;
	while ((str[i] != '-') && (i < str.size()))
	{
		temp_x2.push_back(str[i]);
		++i;
	}
	number.x2 = atoi(temp_x2.c_str());

	i++;
	string temp_x3;
	while ((str[i] != '-') && (i < str.size()))
	{
		temp_x3.push_back(str[i]);
		++i;
	}
	number.x3 = atoi(temp_x3.c_str());
	
	while (!isalpha(str[i]) && !isdigit(str[i]))
	{ 
		++i;
		if (i == str.size())
		  break;
	}
	number.ch = str[i];

	m_genre = i_genre;
}