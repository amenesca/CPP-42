#ifndef CAT_HPP
# define CAT_HPP

#include <iostream>
#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal {

	private:
		Brain* brain;

	public:
		Cat(void);
		~Cat(void);
		Cat(Cat const &copy);
		Cat &operator=(Cat const &equal);

		void makeSound(void) const;
		void think(void) const;

};

#endif