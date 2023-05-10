#include "FlagTrap.hpp"

int main() 
{
	FlagTrap Robo("Genos");
	for (int i = 0; i < 11; i++)
		Robo.attack("assassin robot");
	Robo.takeDamage(50);
	Robo.beRepaired(10);
	Robo.highFivesGuys();
	return (0);
}