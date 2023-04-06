#include "PhoneBook.hpp"

void presentation(void)
{
	std::cout << "\033[34m.-. . . . .-. .-. .-. .  . .-.   .-. . . .-. . . .-. .-. .-. .-. . ." << std::endl;
	std::cout << "|-| | | | |-  `-. | | |\\/| |-    |-' |-| | | |\\| |-  |(  | | | | |<" << std::endl;
	std::cout << "` ' `.'.' `-' `-' `-' '  ` `-'   '   ' ` `-' ' ` `-' `-' `-' `-' ' `\033[0;0m" << std::endl << std::endl;
}

void interface(void)
{
	std::cout << "\033[93mEnter one of the following commands:" << std::endl;
	std::cout << "ADD [Save a new contact]" << std::endl;
	std::cout << "SEARCH [Display a specific contact]" << std::endl;
	std::cout << "EXIT [Exits the program]" << std::endl;
	std::cout << "= \033[0;0m";
	
	return ;
}

void get_command(PhoneBook *myPhonebook, int *running)
{
	std::string comm;
	std::cin >> comm;
	if (comm == "ADD")
		myPhonebook->gather_info();
	else if (comm == "SEARCH")
		return ;
	else if (comm == "EXIT")
		*running = 0;
	else
		std::cout << "\033[93mCommand not found.\033[0;0m" << std::endl << std::endl;
	return ;
}

int main()
{
	PhoneBook myPhonebook;
	int running = 1;

	presentation();
	while (running)
	{
		interface();
		get_command(&myPhonebook, &running);
	}
	return (0);
}