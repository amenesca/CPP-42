#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void)
{
	return ;
}

PhoneBook::~PhoneBook(void)
{
	return ;
}
void PhoneBook::gather_info(int index)
{
	std::string aux;
	int info_accept = 0;

	while (info_accept < 5)
	{
		switch (info_accept)
		{
			case (0):
				std::cout << "Enter your first name: ";
				std::getline(std::cin, aux);
				this->contacts[index].save_info(aux, info_accept);
				break;
			case (1):
				std::cout << "Enter your last name: ";
				std::getline(std::cin, aux);
				this->contacts[index].save_info(aux, info_accept);
				break;
			case(2):
				std::cout << "Enter your nickname: ";
				std::getline(std::cin, aux);
				this->contacts[index].save_info(aux, info_accept);
				break;
			case(3):
				std::cout << "Enter your phone number: ";
				std::getline(std::cin, aux);
				this->contacts[index].save_info(aux, info_accept);
				break;
			case(4):
				std::cout << "Enter your darkest secret: ";
				std::getline(std::cin, aux);
				this->contacts[index].save_info(aux, info_accept);
				break;
		}
		if (aux.size() > 0)
			info_accept++;
		else
			std::cout << "Cannot accept empty input, try again." << std::endl;
	}
	std::cout << std::endl << "Contact saved!\n" << std::endl;
	return ;
}

void PhoneBook::do_search(int quant)
{
	std::string choose;

	if (quant > 7)
		quant = 8;
	if (quant > 0)
		std::cout << "ID|FIRST NAME| LAST NAME|  NICKNAME|" << std::endl;
	for (int index = 0; index < quant; index++)
	{
		std::cout << "------------------------------------" << std::endl;
		this->contacts[index].print_search(index);
	}
	if (quant > 0)
		std::cout << "------------------------------------" << std::endl;
	if (quant > 0)
	{
		std::cout << std::endl << "Enter the index to display the info of the choosen contact: ";
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
			std::cout << std::endl << "Wrong index." << std::endl;
	}
	if (quant == 0)
		std::cout << std::endl << "No contacts found." << std::endl << std::endl;
	return ;
}