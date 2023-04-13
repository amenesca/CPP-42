#ifndef WEAPON_HPP
# define WEAPON_HPP

#include <iostream>

class Weapon {

private:
	std::string type;

public:
	Weapon(std::string type); // Constructor da classe weapon que inicializa a string type
	~Weapon(void);
	std::string const & getType(void);
	void setType(std::string type);
};

#endif