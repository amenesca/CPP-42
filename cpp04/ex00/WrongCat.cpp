#include "WrongCat.hpp"

WrongCat::WrongCat(void) {
	std::cout << "WrongCat default constructor called." << std::endl;
	this->type = "WrongCat";
	return ;
}

WrongCat::~WrongCat(void) {
	std::cout << "WrongCat default destructor called." << std::endl;
	return ;
}

WrongCat::WrongCat(WrongCat const& copy)
{
	std::cout << "WrongCat copy constructor called" << std::endl;
	*this = copy;
	return ;
}

WrongCat& WrongCat::operator=(WrongCat const& equal)
{
	std::cout << "WrongCat copy assignment operator called" << std::endl;
	this->type = equal.type;
	return *this;
}

void WrongCat::makeSound(void) const {
	std::cout << "Mieoa" << std::endl;
	return ;
}