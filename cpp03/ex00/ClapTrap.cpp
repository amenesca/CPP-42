#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void)
{
	this->name = "sometrap";
	this->hitPoints = 10;
	this->energyPoints = 10;
	this->atackDamage = 0;
	std::cout << "ClapTrap Default Constructor Called" << std::endl;
	return ;
}

ClapTrap::ClapTrap(std::string name) {
	this->name = name;
	this->hitPoints = 10;
	this->energyPoints = 10;
	this->atackDamage = 0;
	std::cout << this->name << ": ClapTrap name constructor called" << std::endl;
	return ;
}

ClapTrap::~ClapTrap(void) {
	std::cout << this->name << ":ClapTrap destructor called" << std::endl;
	return ;
}

ClapTrap::ClapTrap(ClapTrap const& copy)
{
	std::cout << this->name << ":ClapTrap copy constructor called" << std::endl;
	*this = copy;
	return ;
}

ClapTrap& ClapTrap::operator=(ClapTrap const& equal)
{
	std::cout << this->name << ":ClapTrap copy assignment operator called" << std::endl;
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
	 " spent 1 energy point attacking "\
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
		else if (this->hitPoints == 0)
		{
			std::cout << "ClapTrap " << this->name <<\
		 " Is dead and can't atack"\
		 << std::endl;
		}
	}
}

void ClapTrap::takeDamage(unsigned int amount) {
	bool condition = 0;

	if (this->hitPoints > 0)
		condition = 1;

	this->hitPoints -= (int)amount;

	if (this->hitPoints < 0)
		this->hitPoints = 0;
	
	if (this->hitPoints == 0 && condition)
	{
		std::cout << this->name << " took "\
		 << amount << " damage and now is dead" << std::endl;
	}
	else if (this->hitPoints == 0 && condition == 0)
	{
		std::cout << this->name << " is dead" << std::endl;
	}
	else
	{
		std::cout << this->name << " took "\
	 << amount << " damage leaving with " << this->hitPoints\
	 << " hit points" << std::endl;
	}
}

void ClapTrap::beRepaired(unsigned int amount) {
	if (this->energyPoints > 0 && this->hitPoints > 0)
	{
		this->hitPoints += (int)amount;

		std::cout << this->name\
		 << " got repaired by " << amount <<\
		 " hit points leaving him with " << this->hitPoints\
		 << " hit points" << std::endl; 
		
		this->energyPoints--;
		
		std::cout << this->name <<\
	 " spent 1 energy point being reapaired leaving with "\
	 << this->energyPoints << " energy points" << std::endl;
	}
	else
	{
		if (this->energyPoints == 0 && this->hitPoints > 0)
		{
			std::cout << this->name <<\
		 " hasn't enough energy points to be repaired"\
		 << std::endl;
		}
		else if (this->hitPoints == 0)
		{
			std::cout << this->name <<\
		 " Is dead and can't be repaired"\
		 << std::endl;
		}
	}
}
