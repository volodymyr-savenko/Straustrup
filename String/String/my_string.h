#include <cstring>
#include <iostream>

template <typename T>
class MyString
{
	public:
		 MyString();
		 MyString(const char* i_c_string);
		 /*MyString(const MyString& i_proto);

		 MyString& operator=(const MyString& i_proto);

		 virtual ~MyString();
		 */
		 void Print();
  private:
	   char* p_first_letter;
		 size_t length;
		 T x;
};

template <typename T>
MyString<T>::MyString() :
{
	p_first_letter = NULL;
	length = 0;
}
//------------------------------------------------
template <typename T>
MyString<T>::MyString(const char* i_c_string)
{
	length = strlen(i_c_string);
	p_first_letter = new char[length + 1];
	for (size_t i = 0; i <= (length + 1); i++)
	{
		p_first_letter[i] = i_c_string[i];
	}
}
//------------------------------------------------
template <typename T>
void MyString<T>::Print()
{
	for (size_t i = 0; i <= (length + 1); i++)
	{
		std::cout << p_first_letter[i];
	}
}