#pragma once
#include <vector>
#include <string>
#include "Book.h"
#include "Patron.h"

class Library
{
  public:
	  Library(){};
		struct Transaction
		{
		  Book m_book;
			Patron m_patron;
		};
		void AddBook(Book i_book);
		void AddPatron(const Patron& i_patron);
		bool AddTransaction(Book i_book, const Patron& i_patron);
		std::vector<string> DebtsList();


	private:
	  std::vector<Book> book_list;
		std::vector<Patron> patron_list;
		std::vector<Transaction> transaction_list;
};