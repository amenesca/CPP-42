#include "HumanB.hpp"

HumanB::HumanB(void){}

HumanB::~HumanB(void){}

void HumanB::attack(void)
{
	std::cout << this->name << " attacks with their " << this->weapon.getType() << std::endl;
}