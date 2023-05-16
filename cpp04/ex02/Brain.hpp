#ifndef BRAIN_HPP
# define BRAIN_HPP

#include <iostream>
#include <sstream>

class Brain {

	private:
		std::string ideas[100];

	public:
		Brain(void);
		~Brain(void);
		Brain(Brain const &copy);
		Brain &operator=(Brain const &equal);

		void setIdeas(std::string type);
		void printIdeas(void);

};

#endif