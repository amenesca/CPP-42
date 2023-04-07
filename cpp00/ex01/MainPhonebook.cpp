#include "PhoneBook.hpp"

void presentation(void)
{
	std::cout << "\033[34m.-. . . . .-. .-. .-. .  . .-.   .-. . . .-. . . .-. .-. .-. .-. . ." << std::endl;
	std::cout << "|-| | | | |-  `-. | | |\\/| |-    |-' |-| | | |\\| |-  |(  | | | | |<" << std::endl;
	std::cout << "` ' `.'.' `-' `-' `-' '  ` `-'   '   ' ` `-' ' ` `-' `-' `-' `-' ' `" << std::endl << std::endl;
}

void interface(void)
{
	std::cout << "Enter one of the following commands:" << std::endl;
	std::cout << "ADD [Save a new contact]" << std::endl;
	std::cout << "SEARCH [Display a specific contact]" << std::endl;
	std::cout << "EXIT [Exits the program]" << std::endl;
	std::cout << "= ";
	
	return ;
}

void get_command(PhoneBook *phonebook, int *running)
{
	static int index;
	static int quant;
	std::string comm;

	if (index == 8)
		index = 0;
	std::getline(std::cin, comm);
	if (comm == "ADD")
	{
		phonebook->gather_info(index);
		index++;
		quant++;
	}
	else if (comm == "SEARCH")
		phonebook->do_search(quant);
	else if (comm == "EXIT")
		*running = 0;
	else
		std::cout << "Command not found." << std::endl << std::endl;
	return ;
}

int main()
{
	PhoneBook phonebook;
	int running = 1;

	presentation();
	while (running)
	{
		interface();
		get_command(&phonebook, &running);
	}
	return (0);
}