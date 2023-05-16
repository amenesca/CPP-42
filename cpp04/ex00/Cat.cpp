#include "Cat.hpp"

Cat::Cat(void) {
	std::cout << "Cat default constructor called." << std::endl;
	this->type = "Cat";
	return ;
}

Cat::~Cat(void) {
	std::cout << "Cat default destructor called." << std::endl;
	return ;
}

Cat::Cat(Cat const& copy)
{
	std::cout << "Cat copy constructor called" << std::endl;
	*this = copy;
	return ;
}

Cat& Cat::operator=(Cat const& equal)
{
	std::cout << "Cat copy assignment operator called" << std::endl;
	this->type = equal.type;
	return *this;
}

void Cat::makeSound(void) const {
	std::cout << "Mieoahuesheuhe" << std::endl;
	return ;
}