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

void Contacts::print_attributes(void)
{
	std::cout << this->attributes[0] << std::endl;
	std::cout << this->attributes[1] << std::endl;
	std::cout << this->attributes[2] << std::endl;
	std::cout << this->attributes[3] << std::endl;
	std::cout << this->attributes[4] << std::endl;
}