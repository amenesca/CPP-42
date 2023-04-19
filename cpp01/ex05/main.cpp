#include "Harl.hpp"

int main ()
{
	Harl alan;

	alan.complain("DEBUG");
	std::cout << std::endl;
	alan.complain("INFO");
	std::cout << std::endl;
	alan.complain("WARNING");
	std::cout << std::endl;
	alan.complain("ERROR");
	alan.complain("UNDEFINED");

	return (0);
}