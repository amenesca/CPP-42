#ifndef DOG_HPP
# define DOG_HPP

#include <iostream>
#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal {

	private:
		Brain* brain;

	public:
		Dog(void);
		~Dog(void);
		Dog(Dog const &copy);
		Dog &operator=(Dog const &equal);

		void makeSound(void) const;
		void think(void) const;

};

#endif