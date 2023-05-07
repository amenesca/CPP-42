#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <string>
# include "iostream"

class ClapTrap {

  private:
    std::string name;
    int hitPoints;
    int energyPoints;
    int atackDamage;

  public:
	ClapTrap();
    ~ClapTrap(void);
    ClapTrap(std::string name);
	ClapTrap(ClapTrap const &copy);
	ClapTrap &operator=(ClapTrap const &equal);
	

    void attack(const std::string& target);
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);
};

#endif
