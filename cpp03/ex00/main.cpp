#include "ClapTrap.hpp"

int main() 
{
	ClapTrap Robot("Genos");
	ClapTrap Robot2(Robot);
	ClapTrap Robot3;

	Robot3 = Robot;
	
	std::cout << std::endl;
	std::cout << "Name constructor test" << std::endl << std::endl;
	for (int i = 0; i < 9; i++)
		Robot.attack("raoni");
	Robot.takeDamage(9);
	Robot.beRepaired(9);
	Robot.takeDamage(10);
	Robot.beRepaired(9);
	Robot.attack("Raoni");
	std::cout << std::endl;

	std::cout << "Copy constructor test" << std::endl << std::endl;
	for (int i = 0; i < 9; i++)
		Robot2.attack("raoni");
	Robot2.takeDamage(9);
	Robot2.beRepaired(9);
	Robot2.takeDamage(10);
	Robot2.beRepaired(9);
	Robot2.attack("Raoni");
	std::cout << std::endl;

	std::cout << "Copy assignment operator test" << std::endl << std::endl;
	for (int i = 0; i < 9; i++)
		Robot3.attack("raoni");
	Robot3.takeDamage(9);
	Robot3.beRepaired(9);
	Robot3.takeDamage(10);
	Robot3.beRepaired(9);
	Robot3.attack("Raoni");
	std::cout << std::endl;
	return (0);
}