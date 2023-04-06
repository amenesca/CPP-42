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

	std::cout << "Enter your first name: ";
	std::cin >> aux;
	this->contacts[index].save_info(aux, FNAME);
	std::cout << "Enter your last name: ";
	std::cin >> aux;
	this->contacts[index].save_info(aux, LNAME);
	std::cout << "Enter your nickname: ";
	std::cin >> aux;
	this->contacts[index].save_info(aux, NNAME);
	std::cout << "Enter your phone number: ";
	std::cin >> aux;
	this->contacts[index].save_info(aux, PNUMBER);
	std::cout << "Enter your darkest secret: ";
	std::cin >> aux;
	this->contacts[index].save_info(aux, DSECRET);
	std::cout << std::endl << "Contact saved!" << std::endl << std::endl;
	return ;
}

void PhoneBook::do_search(int quant)
{
	std::string choose;

	if (quant > 7)
		quant = 8;
	for (int index = 0; index < quant; index++)
		this->contacts[index].print_search(index);
	if (quant > 0)
	{
		std::cout << "Enter the index to display the info of the choosen contact: ";
		std::cin >> choose;
		if (choose == "1" && quant > 0)
			this->contacts[0].print_info();
		else if (choose == "2" && quant > 1)
			this->contacts[1].print_info();
		else if (choose == "3" && quant > 2)
			this->contacts[2].print_info();
		else if (choose == "4" && quant > 3)
			this->contacts[3].print_info();
		else if (choose == "5" && quant > 4)
			this->contacts[4].print_info();
		else if (choose == "6" && quant > 5)
			this->contacts[5].print_info();
		else if (choose == "7" && quant > 6)
			this->contacts[6].print_info();
		else if (choose == "8" && quant > 7)
			this->contacts[7].print_info();
		else
			std::cout << "Wrong index." << std::endl;
	}
	if (quant == 0)
		std::cout << "No contacts found." << std::endl << std::endl;
	return ;
}