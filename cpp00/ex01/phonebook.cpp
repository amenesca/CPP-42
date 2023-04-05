#include <iostream>

int main(void)
{
	std::string	empty = "          ";

	std::cout << "\033[32m.-. . . . .-. .-. .-. .  . .-.   .-. . . .-. . . .-. .-. .-. .-. . .\033[0;0m" << std::endl;
	std::cout << "\033[32m|-| | | | |-  `-. | | |\\/| |-    |-' |-| | | |\\| |-  |(  | | | | |<\033[0;0m" << std::endl;
	std::cout << "\033[32m` ' `.'.' `-' `-' `-' '  ` `-'   '   ' ` `-' ' ` `-' `-' `-' `-' ' `\033[0;0m" << std::endl;
	std::cout << "\033[32m.------------.-----------.----------.--------------.----------------.\033[0;0m" << std::endl;
	std::cout << "\033[1;32m| FIRST NAME | LAST NAME | NICKNAME | PHONE NUMBER | DARKEST SECRET |\033[0;0m" << std::endl;
	std::cout << "\033[32m.------------.-----------.----------.--------------.----------------.\033[0;0m" << std::endl;


	for (int i = 0; i < 5; i++) 
	{
		std::cout << "|" << empty;
	}
	std::cout << "|";
	return (0);
}