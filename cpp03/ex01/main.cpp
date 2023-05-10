#include "ScavTrap.hpp"

int main() 
{
	ScavTrap Robo("Genos");
	for (int i = 0; i < 11; i++)
		Robo.attack("assassin robot");
	Robo.takeDamage(50);
	Robo.beRepaired(10);
	Robo.guardGate();
	return (0);
}