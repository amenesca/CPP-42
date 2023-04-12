#include "./Zombie.hpp"

int main()
{
	int N;
	Zombie *zombies;
	std::string name;
	
	N = 5;
	name = "Hordinary";
	zombies = zombieHorde(N, name);
	for (int i = 0; i < N; i++)
		zombies[i].announce();

	delete [] zombies;
	return (0);
}