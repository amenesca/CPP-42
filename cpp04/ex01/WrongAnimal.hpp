#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

#include <iostream>

class WrongAnimal {

	protected:
		std::string type;

	public:
		WrongAnimal(void);
		virtual ~WrongAnimal(void);
		WrongAnimal(WrongAnimal const &copy);
		WrongAnimal &operator=(WrongAnimal const &equal);

		std::string getType(void) const ;

		void makeSound(void) const ;

};

#endif