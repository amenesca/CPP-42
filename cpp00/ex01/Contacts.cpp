#include "Contacts.hpp"

Contacts::Contacts(void)
{
//	std::cout << "Contacts instanciado\n";
	return ;
}

Contacts::~Contacts(void)
{
//	std::cout << "Contacts destruido\n";
	return ;
}

void Contacts::save_info(std::string attribute, int att)
{
	this->attributes[att] = attribute;
	return ;
}

void Contacts::print_search(int index)
{
	std::string choose;

	std::cout << " " << index + 1 << "|";
	for (int i = 0; i < 3; i++)
	{
		right_align(this->attributes[i]);
		std::cout << "|";
	}
	std::cout << std::endl;
}

void Contacts::right_align(std::string attribute)
{
	int spc_quant;
	int i = -1;

	if (attribute.size() < 10)
	{
		spc_quant = 10 - attribute.size();
		while (spc_quant--)
			std::cout << " ";
		std::cout << attribute;
	}
	else if (attribute.size() > 10)
	{
		while (++i < 9)
			std::cout << attribute[i];
		std::cout << ".";
	}
	else
		std::cout << attribute;
	return ;
}

void Contacts::print_info(void)
{
	std::cout << "First Name: " << this->attributes[0] << std::endl;
	std::cout << "Last Name: " << this->attributes[1] << std::endl;
	std::cout << "Nickname: " << this->attributes[2] << std::endl;
	std::cout << "Phone Number: " << this->attributes[3] << std::endl;
	std::cout << "Darkest Secret: " << this->attributes[4] << std::endl;
}