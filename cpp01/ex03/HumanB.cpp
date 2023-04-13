#include "HumanB.hpp"

HumanB::HumanB(void) {
	return ;
}

HumanB::~HumanB(void) {
	return ;
}

void HumanB::attack(void) {
	std::cout << this->name << " attacks with their " << this->weapon.getType() << std::endl;
	return ;
}