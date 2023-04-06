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

void get_command(PhoneBook *phonebook, int *running, int index)
{
	std::string comm;
	std::cin >> comm;
	if (comm == "ADD")
		phonebook->gather_info(index);
	else if (comm == "SEARCH")
		phonebook->do_search(index);
	else if (comm == "EXIT")
		*running = 0;
	else
		std::cout << "\033[93mCommand not found.\033[0;0m" << std::endl << std::endl;
	return ;
}

int main()
{
	PhoneBook phonebook;
	int running = 1;
	int index = 0;
	int quant = 0;

	presentation();
	while (running)
	{
		if (index == 8)
			index = 0;
		interface();
		get_command(&phonebook, &running, &i);
		quant++;
	}
	return (0);
}