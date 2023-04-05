#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "Contacts.hpp"

class	PhoneBook {

private:
	Contacts contacts[8];

public:
	PhoneBook (void);
	~PhoneBook (void);
	void	gather_info(void);
	void	print_info(void);

};

#endif