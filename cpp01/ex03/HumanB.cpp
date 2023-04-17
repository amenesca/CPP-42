#include "HumanB.hpp"

HumanB::HumanB(std::string name) : name(name) {
	return ;
}

HumanB::~HumanB(void) {
	return ;
}

void HumanB::setWeapon(Weapon* weapon)
{
	this->weapon = weapon;
}

void HumanB::attack(void) const {
	std::cout << this->name << " attacks with their " << this->weapon->getType() << std::endl;
	return ;
}