#include "./Zombie.hpp"

int main( void )
{
	Zombie *zombieHeap;
	std::string name;

	name = "Heaper";
	zombieHeap = newZombie(name);
	zombieHeap->announce();
	name = "Stacker";
	randomChump(name);
	delete zombieHeap;
	return (0);
}