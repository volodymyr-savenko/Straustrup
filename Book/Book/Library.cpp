#include "stdafx.h"
#include "Library.h"
#include <algorithm>

void Library::AddBook(Book i_book)
{
	book_list.push_back(i_book);
}
void Library::AddPatron(const Patron& i_patron)
{
	patron_list.push_back(i_patron);
}
bool Library::AddTransaction(Book i_book, const Patron& i_patron)
{
	if (book_list.end() == find(book_list.begin(), book_list.end(), i_book))
	  return false;
	if (patron_list.end() == find(patron_list.begin(), patron_list.end(), i_patron))
		return false;
	Transaction temp_transaction;
	temp_transaction.m_book = i_book;
	temp_transaction.m_patron = i_patron;
	if (!i_patron.ValidFee())
	  return false;
	transaction_list.push_back(temp_transaction);
	  return true;
}
std::vector<string> Library::DebtsList()
{
	std::vector<string> temp;
	for_each(patron_list.begin(), patron_list.end(), [&temp](Patron current_patron){
		if (!current_patron.ValidFee());
		temp.push_back(current_patron.Name());
	});
	return temp;
}