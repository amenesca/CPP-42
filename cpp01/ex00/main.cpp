#include "./Zombie.hpp"

int main( void )
{
	Zombie *zombie;
	zombie = NULL;
	std::string name = "alan";

	zombie = zombie->newZombie(name);
	zombie->announce();

}