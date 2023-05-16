#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <string>

class Animal {

	protected:
		std::string type;

	public:
		Animal(void);
		~Animal(void);
		Animal(std::string name);
		Animal(Animal const &copy);
		Animal &operator=(Animal const &equal);

};

#endif