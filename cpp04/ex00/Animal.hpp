#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <iostream>

class Animal {

	protected:
		std::string type;

	public:
		Animal(void);
		virtual ~Animal(void);
		Animal(Animal const &copy);
		Animal &operator=(Animal const &equal);

		std::string getType(void) const ;

		virtual void makeSound(void) const ;

};

#endif