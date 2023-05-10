#include "ClapTrap.hpp"

int main() 
{
	ClapTrap Robo("Genos");
	for (int i = 0; i < 11; i++)
		Robo.attack("assassin robot");
	Robo.takeDamage(50);
	Robo.takeDamage(10);
	Robo.beRepaired(10);
	return (0);
}