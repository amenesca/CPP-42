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
	std::cout << " " << index << " |"; 
}