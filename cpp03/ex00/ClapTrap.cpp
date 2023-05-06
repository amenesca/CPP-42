#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name) : name(name) , hitPoints(10) , energyPoints(10) , atackDamage(0) {
	std::cout << this->name << ": Aaaaand... OPEN!" << std::endl;
	return ;
}

ClapTrap::~ClapTrap(void) {
	std::cout << this->name << ": Aaaaand... CLOSE." << std::endl;
	return ;
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
		if (this->energyPoints < 0 && this->hitPoints > 0)
		{
			std::cout << "ClapTrap " << this->name <<\
		 " hasn't enough energy points to take this action"\
		 << std::endl;
		}
		else if (this->energyPoints > 0 && this->hitPoints <= 0)
		{
			std::cout << "ClapTrap " << this->name <<\
		 " hasn't enough hit points to take this action"\
		 << std::endl;
		}
		else
		{
			std::cout << "ClapTrap " << this->name <<\
		 " hasn't enough points to take this action"\
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
		if (this->energyPoints < 0 && this->hitPoints > 0)
		{
			std::cout << "ClapTrap " << this->name <<\
		 " hasn't enough energy points to take this action"\
		 << std::endl;
		}
		else if (this->energyPoints > 0 && this->hitPoints <= 0)
		{
			std::cout << "ClapTrap " << this->name <<\
		 " hasn't enough hit points to take this action"\
		 << std::endl;
		}
		else
		{
			std::cout << "ClapTrap " << this->name <<\
		 " hasn't enough points to take this action"\
		 << std::endl;
		}
	}
}
