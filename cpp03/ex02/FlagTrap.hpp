#ifndef FLAGTRAP_HPP
# define FLAGTRAP_HPP

#include "ClapTrap.hpp"

class FlagTrap : public ClapTrap {

	public:
		FlagTrap(void);
		~FlagTrap(void);
		FlagTrap(std::string name);
		FlagTrap(FlagTrap const &copy);
		FlagTrap &operator=(FlagTrap const &equal);

		void highFivesGuys(void);
};

#endif