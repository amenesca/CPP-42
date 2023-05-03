#include "ClapTrap.hpp"

int main() 
{
	ClapTrap Robo("robo");
	Robo.attack("burro");
	Robo.takeDamage(10);
	Robo.beRepaired(10);
	return (0);
}