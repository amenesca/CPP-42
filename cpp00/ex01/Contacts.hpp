#ifndef CONTACTS_HPP
# define CONTACTS_HPP

#include <iostream>

class Contacts {

private:
	std::string attributes[5];

public:
	#define FNAME 0
	#define LNAME 1
	#define NNAME 2
	#define PNUMBER 3
	#define DSECRET 4

	Contacts (void);
	~Contacts (void);

	void save_info(std::string attribute, int att);
	void print_search(int index);
};

#endif