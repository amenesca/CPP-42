#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void) {
	std::cout << "WrongAnimal default constructor called." << std::endl;
	this->type = "default";
	return ;
}

WrongAnimal::~WrongAnimal(void) {
	std::cout << "WrongAnimal default destructor called." << std::endl;
	return ;
}

WrongAnimal::WrongAnimal(WrongAnimal const& copy)
{
	std::cout << "WrongAnimal copy constructor called" << std::endl;
	*this = copy;
	return ;
}

WrongAnimal& WrongAnimal::operator=(WrongAnimal const& equal)
{
	std::cout << "WrongAnimal copy assignment operator called" << std::endl;
	this->type = equal.type;
	return *this;
}

std::string WrongAnimal::getType(void) const {
	return (this->type);
}

void WrongAnimal::makeSound(void) const {
	std::cout << "undefined sound" << std::endl;
	return ;
}