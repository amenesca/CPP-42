#include "PhoneBook.hpp"

void presentetion(void)
{
	std::cout << "\u001B[36m.-. . . . .-. .-. .-. .  . .-.   .-. . . .-. . . .-. .-. .-. .-. . ." << std::endl;
	std::cout << "|-| | | | |-  `-. | | |\\/| |-    |-' |-| | | |\\| |-  |(  | | | | |<" << std::endl;
	std::cout << "` ' `.'.' `-' `-' `-' '  ` `-'   '   ' ` `-' ' ` `-' `-' `-' `-' ' `\u001B[0m" << std::endl << std::endl;
}

void initial_interface(void)
{
	std::cout << "\u001B[34mEnter one of the following commands:\u001B[0m" << std::endl;
	std::cout << "\u001B[36mADD [Save a new contact]" << std::endl;
	std::cout << "SEARCH [Display a specific contact]" << std::endl;
	std::cout << "EXIT [Exits the program]\u001B[0m" << std::endl;
	
	return ;
}

int main()
{
//	PhoneBook myPhonebook;

	presentetion();
	initial_interface();
//	myPhonebook.gather_info();
//	myPhonebook.print_info();
	return (0);
}