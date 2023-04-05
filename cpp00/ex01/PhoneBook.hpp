#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include <iostream>
#include "Contacts.hpp"

class	PhoneBook {

private:
	Contacts contacts[8];
	

public:
	PhoneBook (void);
	~PhoneBook (void);

};

#endif