#include "Harl.hpp"

int main (int argc, char *argv[])
{
	Harl alan;

	if (argc != 2)
		return (1);
	alan.complain(argv[1]);
	return (0);
}