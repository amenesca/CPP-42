#include "Harl.hpp"

int main ()
{
	Harl alan;

	alan.complain("DEBUG");
	alan.complain("INFO");
	alan.complain("WARNING");
	alan.complain("ERROR");
	alan.complain("UNDEFINED");

	return (0);
}