#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void)
{
	std::cout << "Default Constructor Called" << std::endl;
	return ;
}

ClapTrap::ClapTrap(std::string name) : name(name) , hitPoints(10) , energyPoints(10) , atackDamage(0) {
	std::cout << this->name << ": name constructor called" << std::endl;
	return ;
}

ClapTrap::~ClapTrap(void) {
	std::cout << this->name << ": destructor called" << std::endl;
	return ;
}

ClapTrap::ClapTrap(ClapTrap const& copy)
{
	std::cout << this->name << ": copy constructor called" << std::endl;
	*this = copy;
	return ;
}

ClapTrap& ClapTrap::operator=(ClapTrap const& equal)
{
	std::cout << this->name << ": copy assignment operator called" << std::endl;
	this->energyPoints = equal.energyPoints;
	this->hitPoints = equal.hitPoints;
	this->name = equal.name;
	this->atackDamage = equal.atackDamage;
	
	return *this;
}

void ClapTrap::attack(const std::string& target) {
	if (this->energyPoints > 0 && this->hitPoints > 0)
	{	
		std::cout << "ClapTrap " << this->name << " attacks " <<\
	 target << ", causing " << this->atackDamage <<\
	 " points of damage!" << std::endl;
	 
	 	this->energyPoints--;
		
		std::cout << "ClapTrap " << this->name <<\
	 " spent 1 energy point attacking " << target\
	 << " leaving with " << this->energyPoints\
	 << " energy points" << std::endl;
	}
	else
	{
		if (this->energyPoints == 0 && this->hitPoints > 0)
		{
			std::cout << "ClapTrap " << this->name <<\
		 " hasn't enough energy points to atack"\
		 << std::endl;
		}
		else if (this->energyPoints > 0 && this->hitPoints == 0)
		{
			std::cout << "ClapTrap " << this->name <<\
		 " hasn't enough hit points to atack"\
		 << std::endl;
		}
		else
		{
			std::cout << "ClapTrap " << this->name <<\
		 " hasn't enough points to atack"\
		 << std::endl;
		}
	}
}

void ClapTrap::takeDamage(unsigned int amount) {
	this->hitPoints -= (int)amount;

	if (this->hitPoints < 0)
		this->hitPoints = 0;
	
	std::cout << "ClapTrap " << this->name << " took "\
 << amount << " damage leaving him with " << this->hitPoints\
 << " hit points" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount) {
	if (this->energyPoints > 0 && this->hitPoints > 0)
	{
		this->hitPoints += (int)amount;

		std::cout << "ClapTrap " << this->name\
		 << " got repaired by " << amount <<\
		 " hit points leaving him with " << this->hitPoints\
		 << " hit points" << std::endl; 
		
		this->energyPoints--;
		
		std::cout << "ClapTrap " << this->name <<\
	 " spent 1 energy point being reapaired leaving with "\
	 << this->energyPoints << " energy points" << std::endl;
	}
	else
	{
		if (this->energyPoints == 0 && this->hitPoints > 0)
		{
			std::cout << "ClapTrap " << this->name <<\
		 " hasn't enough energy points to be repaired"\
		 << std::endl;
		}
		else if (this->energyPoints > 0 && this->hitPoints == 0)
		{
			std::cout << "ClapTrap " << this->name <<\
		 " hasn't enough hit points to be repaired"\
		 << std::endl;
		}
		else
		{
			std::cout << "ClapTrap " << this->name <<\
		 " hasn't enough points to be repaired"\
		 << std::endl;
		}
	}
}
