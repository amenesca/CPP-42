#ifndef DOG_HPP
# define DOG_HPP

#include <string>
#include "Animal.hpp"

class Dog : public Animal {

	public:
		Dog(void);
		~Dog(void);
		Dog(std::string name);
		Dog(Dog const &copy);
		Dog &operator=(Dog const &equal);

};

#endif