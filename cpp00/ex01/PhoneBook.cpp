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
	int is_blank = 0;

	while (++is_blank)
	{
		std::cout << "Enter your first name: ";
		std::getline(std::cin, aux);
		this->contacts[index].save_info(aux, FNAME);
		if (aux.size() > 0)
			is_blank = -1;
		else
			std::cout << "Cannot accept empty input, try again." << std::endl;
	}
	while (++is_blank)
	{
		std::cout << "Enter your last name: ";
		std::getline(std::cin, aux);
		this->contacts[index].save_info(aux, LNAME);
		if (aux.size() > 0)
			is_blank = -1;
		else
			std::cout << "Cannot accept empty input, try again." << std::endl;
	}
	while (++is_blank)
	{
		std::cout << "Enter your nickname: ";
		std::getline(std::cin, aux);
		this->contacts[index].save_info(aux, NNAME);
		if (aux.size() > 0)
			is_blank = -1;
		else
			std::cout << "Cannot accept empty input, try again." << std::endl;
	}
	while (++is_blank)
	{
		std::cout << "Enter your phone number: ";
		std::getline(std::cin, aux);
		this->contacts[index].save_info(aux, PNUMBER);
		if (aux.size() > 0)
			is_blank = -1;
		else
			std::cout << "Cannot accept empty input, try again." << std::endl;
	}
	while (++is_blank)
	{
		std::cout << "Enter your darkest secret: ";
		std::getline(std::cin, aux);
		this->contacts[index].save_info(aux, DSECRET);
		if (aux.size() > 0)
			is_blank = -1;
		else
			std::cout << "Cannot accept empty input, try again." << std::endl;
	}
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
		std::getline(std::cin, choose);
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