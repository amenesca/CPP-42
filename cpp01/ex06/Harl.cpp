#include "Harl.hpp"

Harl::Harl(void) {
	return ;
}

Harl::~Harl(void) {
	return ;
}

void Harl::debug(void) {
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special- ketchup burger. I really do!" << std::endl;
}

void Harl::info(void) {
	std::cout << "I cannot believe adding extra bacon costs more money. You didn't put enough bacon in my burger! If you did, I wouldn't be asking for more!" << std::endl;
}

void Harl::warning(void) {
	std::cout << "I think I deserve to have some extra bacon for free. I've been coming for years whereas you started working here since last month." << std::endl;
}

void Harl::error(void) {
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

void Harl::complain(std::string level) {

	std::string badclient[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	int i = -1;

	while (i != 4 && badclient[++i] != level) {}

	switch (i) {
			case(0):
				std::cout << "[ " << badclient[0] << " ]" << std::endl;
				this->debug();
				std::cout << std::endl;
			case(1):
				std::cout << "[ " << badclient[1] << " ]" << std::endl;
				this->info();
				std::cout << std::endl;
			case(2):
				std::cout << "[ " << badclient[2] << " ]" << std::endl;
				this->warning();
				std::cout << std::endl;
			case(3):
				std::cout << "[ " << badclient[3] << " ]" << std::endl;
				this->error();
				std::cout << std::endl;
				break;
			default:
				std::cout << "[ Probably complaining about insignificant problem ]" << std::endl;
				return;
	}
	return ;
}