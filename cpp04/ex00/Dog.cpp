#include "Dog.hpp"

Dog::Dog(void) {
	std::cout << "Dog default constructor called." << std::endl;
	this->type = "Dog";
	return ;
}

Dog::~Dog(void) {
	std::cout << "Dog default destructor called." << std::endl;
	return ;
}

Dog::Dog(Dog const& copy)
{
	std::cout << "Dog copy constructor called" << std::endl;
	*this = copy;
	return ;
}

Dog& Dog::operator=(Dog const& equal)
{
	std::cout << "Dog copy assignment operator called" << std::endl;
	this->type = equal.type;
	return *this;
}

void Dog::makeSound(void) const {
	std::cout << "Aur Aur Aurhue" << std::endl;
	return ;
}