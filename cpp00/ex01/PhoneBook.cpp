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
void PhoneBook::gather_info(void)
{
	std::string aux;

	std::cout << "Enter your first name: ";
	std::cin >> aux;

	this->contacts[0].save_info(aux);

	return ;
}

void PhoneBook::print_info(void)
{
	this->contacts[0].print_attributes();
}