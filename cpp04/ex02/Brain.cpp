#include "Brain.hpp"

Brain::Brain(void) {
	std::cout << "Brain default constructor called." << std::endl;
	return ;
}

Brain::~Brain(void) {
	std::cout << "Brain default destructor called." << std::endl;
	return ;
}

Brain::Brain(Brain const& copy)
{
	std::cout << "Brain copy constructor called" << std::endl;
	*this = copy;
	return ;
}

Brain& Brain::operator=(Brain const& equal)
{
	std::cout << "Brain copy assignment operator called" << std::endl;
	for (int i = 0; i < 100; i++)
		this->ideas[i] = equal.ideas[i];
	return *this;
}

void Brain::setIdeas(std::string type) {

	std::stringstream ss;

	if (type == "Dog")
	{
		for (int i = 0; i < 100; i++)
		{
			ss << i;
			this->ideas[i] = "bone " + ss.str();
			ss.str("");
		}
	}
	if (type == "Cat")
	{
		for (int i = 0; i < 100; i++)
		{
			ss << i;
			this->ideas[i] = "purr " + ss.str();
			ss.str("");
		}
	}

	return ;
}

void Brain::printIdeas(void) {
	for (int i = 0; i < 100; i++)
	std::cout << this->ideas[i] << std::endl;
	return ;
}