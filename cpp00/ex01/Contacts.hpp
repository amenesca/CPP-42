#ifndef CONTACTS_HPP
# define CONTACTS_HPP

#include <iostream>
#include <string>

class Contacts {

private:
	std::string attributes[5];

public:
	Contacts (void);
	~Contacts (void);

	void save_info(std::string attribute, int att);
	void print_search(int index);
	void right_align(std::string attribute);
	void print_info(void);
};

#endif