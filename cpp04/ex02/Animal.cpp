#include "Animal.hpp"

AAnimal::AAnimal(void) {
	std::cout << "AAnimal default constructor called." << std::endl;
	this->type = "default";
	return ;
}

AAnimal::AAnimal(std::string type) {
	std::cout << "AAnimal type constructor called." << std::endl;
	this->type = type;
	return ;
}

AAnimal::~AAnimal(void) {
	std::cout << "AAnimal default destructor called." << std::endl;
	return ;
}

AAnimal::AAnimal(AAnimal const& copy)
{
	std::cout << "AAnimal copy constructor called" << std::endl;
	*this = copy;
	return ;
}

AAnimal& AAnimal::operator=(AAnimal const& equal)
{
	std::cout << "AAnimal copy assignment operator called" << std::endl;
	this->type = equal.type;
	return *this;
}

std::string AAnimal::getType(void) const {
	return (this->type);
}