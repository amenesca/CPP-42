#include "FlagTrap.hpp"

FlagTrap::FlagTrap(void)
{
	this->name = "sometrap";
	this->hitPoints = 100;
	this->energyPoints = 100;
	this->atackDamage = 30;
	std::cout << "FlagTrap Default Constructor Called" << std::endl;
	return ;
}

FlagTrap::FlagTrap(std::string name) {
	this->name = name;
	this->hitPoints = 100;
	this->energyPoints = 100;
	this->atackDamage = 30;
	std::cout << this->name << ": FlagTrap name constructor called" << std::endl;
	
	return ;
}

FlagTrap::~FlagTrap(void) {
	std::cout << this->name << ": FlagTrap destructor called" << std::endl;
	return ;
}

FlagTrap::FlagTrap(FlagTrap const& copy) : ClapTrap(copy)
{
	*this = copy;
	std::cout << ": FlagTrap copy constructor called" << std::endl;
	return ;
}

FlagTrap& FlagTrap::operator=(FlagTrap const& equal)
{
	this->energyPoints = equal.energyPoints;
	this->hitPoints = equal.hitPoints;
	this->name = equal.name;
	this->atackDamage = equal.atackDamage;
	std::cout << this->name << ": FlagTrap copy assignment operator called" << std::endl;
	
	return *this;
}

void FlagTrap::highFivesGuys(void) {
	if (this->hitPoints > 0)
		std::cout << this->name << " is requesting a positive high five!" << std::endl;
	else
		std::cout << this->name << " is dead and can't request a positive high five!" << std::endl;
}