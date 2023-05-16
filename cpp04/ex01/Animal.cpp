#include "Animal.hpp"

Animal::Animal(void) {
	std::cout << "Animal default constructor called." << std::endl;
	this->type = "default";
	return ;
}

Animal::~Animal(void) {
	std::cout << "Animal default destructor called." << std::endl;
	return ;
}

Animal::Animal(Animal const& copy)
{
	std::cout << "Animal copy constructor called" << std::endl;
	*this = copy;
	return ;
}

Animal& Animal::operator=(Animal const& equal)
{
	std::cout << "Animal copy assignment operator called" << std::endl;
	this->type = equal.type;
	return *this;
}

std::string Animal::getType(void) const {
	return (this->type);
}

void Animal::makeSound(void) const {
	std::cout << "undefined sound" << std::endl;
	return ;
}