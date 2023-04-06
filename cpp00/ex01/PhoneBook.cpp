#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void)
{
//	std::cout << "PhoneBook instanciado\n";
	return ;
}

PhoneBook::~PhoneBook(void)
{
// 	std::cout << "PhoneBook destruido\n";
	return ;
}
void PhoneBook::gather_info(int index)
{
	std::string aux;

	std::cout << "\033[93mEnter your first name: \033[0;0m";
	std::cin >> aux;
	this->contacts[index].save_info(aux, FNAME);
	std::cout << "\033[93mEnter your last name: \033[0;0m";
	std::cin >> aux;
	this->contacts[index].save_info(aux, LNAME);
	std::cout << "\033[93mEnter your nickname name: \033[0;0m";
	std::cin >> aux;
	this->contacts[index].save_info(aux, NNAME);
	std::cout << "\033[93mEnter your phone number name: \033[0;0m";
	std::cin >> aux;
	this->contacts[index].save_info(aux, PNUMBER);
	std::cout << "\033[93mEnter your darkest secret name: \033[0;0m";
	std::cin >> aux;
	this->contacts[index].save_info(aux, DSECRET);
	std::cout << "\033[91mContact saved!\033[0;0m" << std::endl << std::endl;
	return ;
}

void PhoneBook::do_search(int quant)
{
	if (quant > 7)
		quant = 8;
	for (int index = 0; index < quant; index++)
		this->contacts[index].print_search(index);
	return ;
}