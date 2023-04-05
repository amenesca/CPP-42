#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void)
{
	std::cout << "PhoneBook instanciado\n";
	return ;
}

PhoneBook::~PhoneBook(void)
{
	std::cout << "PhoneBook destruido\n";
	return ;
}

int main()
{
	PhoneBook phone;

	return (0);
}