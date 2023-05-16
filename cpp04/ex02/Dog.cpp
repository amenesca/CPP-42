#include "Dog.hpp"

Dog::Dog(void) {
	std::cout << "Dog default constructor called." << std::endl;
	this->type = "Dog";
	this->brain = new Brain();
	this->brain->setIdeas(this->type);
	return ;
}

Dog::Dog(std::string type) {
	std::cout << "Dog type constructor called." << std::endl;
	this->type = type;
	this->brain = new Brain();
	this->brain->setIdeas(this->type);
	return ;
}

Dog::~Dog(void) {
	delete this->brain;
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
	this->brain = new Brain(*equal.brain);
	return *this;
}

void Dog::makeSound(void) const {
	std::cout << "Aur Aur Aurhue" << std::endl;
	return ;
}

void Dog::think(void) const {
	this->brain->printIdeas();
}