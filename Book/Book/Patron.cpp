#include "stdafx.h"
#include "Patron.h"

size_t Patron::current_number = 0;

Patron::Patron(string i_name) : m_name(i_name), valid_fee(false)
{
  m_number = current_number++;
}
string Patron::Name() const
{
	return m_name;
}
size_t Patron::Number() const
{
	return m_number;
}
double Patron::GetFee() const
{
	return m_fee;
}
void Patron::SetFee(double i_fee)
{
	m_fee = i_fee;
}
void Patron::PayFee()
{
	valid_fee = true;
}
bool Patron::ValidFee()
{
	return valid_fee;
}