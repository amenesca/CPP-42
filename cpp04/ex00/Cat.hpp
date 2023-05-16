#ifndef CAT_HPP
# define CAT_HPP

#include <string>
#include "Animal.hpp"

class Cat : public Animal {

	public:
		Cat(void);
		~Cat(void);
		Cat(std::string name);
		Cat(Cat const &copy);
		Cat &operator=(Cat const &equal);

};

#endif