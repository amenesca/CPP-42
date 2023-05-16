#include "Cat.hpp"

Cat::Cat(void) {
	std::cout << "Cat default constructor called." << std::endl;
	this->type = "Cat";
	this->brain = new Brain();
	this->brain->setIdeas(this->type);
	return ;
}

Cat::Cat(std::string type) {
	std::cout << "Cat type constructor called." << std::endl;
	this->type = type;
	this->brain = new Brain();
	this->brain->setIdeas(this->type);
	return ;
}

Cat::~Cat(void) {
	std::cout << "Cat default destructor called." << std::endl;
	delete this->brain;
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
	this->brain = new Brain(*equal.brain);
	return *this;
}

void Cat::makeSound(void) const {
	std::cout << "Mieoahuesheuhe" << std::endl;
	return ;
}

void Cat::think(void) const {
	this->brain->printIdeas();
}