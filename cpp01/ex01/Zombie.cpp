#include "./Zombie.hpp"

Zombie::Zombie(void) 
{
	return ;
}

Zombie::~Zombie(void)
{
	std::cout << this->name << ": was destroyed!" << std::endl;
	return ;
}

void Zombie::announce(void)
{
	std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::nameZombie(std::string name)
{
	this->name = name;
	return ;
}