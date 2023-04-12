#include "./Zombie.hpp"

Zombie::Zombie(std::string name) : name(name)
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