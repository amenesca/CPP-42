#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void)
{
	this->name = "sometrap";
	this->hitPoints = 100;
	this->energyPoints = 50;
	this->atackDamage = 20;
	std::cout << "ScavTrap Default Constructor Called" << std::endl;
	return ;
}

ScavTrap::ScavTrap(std::string name) {
	this->name = name;
	this->hitPoints = 100;
	this->energyPoints = 50;
	this->atackDamage = 20;
	std::cout << this->name << ": ScavTrap name constructor called" << std::endl;
	
	return ;
}

ScavTrap::~ScavTrap(void) {
	std::cout << this->name << ": ScavTrap destructor called" << std::endl;
	return ;
}

ScavTrap::ScavTrap(ScavTrap const& copy) : ClapTrap(copy)
{
	std::cout << ": ScavTrap copy constructor called" << std::endl;
	*this = copy;
	return ;
}

ScavTrap& ScavTrap::operator=(ScavTrap const& equal)
{
	std::cout << this->name << ": ScavTrap copy assignment operator called" << std::endl;
	this->energyPoints = equal.energyPoints;
	this->hitPoints = equal.hitPoints;
	this->name = equal.name;
	this->atackDamage = equal.atackDamage;
	
	return *this;
}

void ScavTrap::attack(const std::string& target) {
	if (this->energyPoints > 0 && this->hitPoints > 0)
	{	
		std::cout << "ScavTrap " << this->name << " attacks " <<\
	 target << ", causing " << this->atackDamage <<\
	 " points of damage!" << std::endl;
	 
	 	this->energyPoints--;
		
		std::cout << this->name <<\
	 " spent 1 energy point attacking " << target\
	 << " leaving with " << this->energyPoints\
	 << " energy points" << std::endl;
	}
	else
	{
		if (this->energyPoints == 0 && this->hitPoints > 0)
		{
			std::cout << this->name <<\
		 " hasn't enough energy points to atack"\
		 << std::endl;
		}
		else if (this->hitPoints == 0)
		{
			std::cout << this->name <<\
		 " Is dead and can't atack"\
		 << std::endl;
		}
	}
}

void ScavTrap::guardGate(void) {
	if (this->hitPoints > 0)
		std::cout << "ScavTrap " << this->name << " is now in Gate Keeper mode" << std::endl;
	else
		std::cout << "ScavTrap " << this->name << " is dead and can't be in Gate Keeper mode" << std::endl;
}