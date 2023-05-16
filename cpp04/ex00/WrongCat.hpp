#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

#include <iostream>
#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal {

	public:
		WrongCat(void);
		~WrongCat(void);
		WrongCat(WrongCat const &copy);
		WrongCat &operator=(WrongCat const &equal);

		void makeSound(void) const;

};

#endif