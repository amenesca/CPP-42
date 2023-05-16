#ifndef DOG_HPP
# define DOG_HPP

#include <iostream>
#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public AAnimal {

	private:
		Brain* brain;

	public:
		Dog(void);
		Dog(std::string type);
		~Dog(void);
		Dog(Dog const &copy);
		Dog &operator=(Dog const &equal);

		virtual void makeSound(void) const;
		void think(void) const;

};

#endif