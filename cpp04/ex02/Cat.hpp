#ifndef CAT_HPP
# define CAT_HPP

#include <iostream>
#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public AAnimal {

	private:
		Brain* brain;

	public:
		Cat(void);
		Cat(std::string type);
		~Cat(void);
		Cat(Cat const &copy);
		Cat &operator=(Cat const &equal);

		virtual void makeSound(void) const;
		void think(void) const;

};

#endif