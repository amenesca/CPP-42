#include "Contacts.hpp"

Contacts::Contacts(void)
{
	std::cout << "Contacts instanciado\n";
	return ;
}

Contacts::~Contacts(void)
{
	std::cout << "Contacts destruido\n";
	return ;
}

void Contacts::save_info(std::string attribute)
{
	this->attributes[0] = attribute;
	return ;
}

void Contacts::print_attributes(void)
{
	std::cout << this->attributes[0] << std::endl;
}