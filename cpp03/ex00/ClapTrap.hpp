#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <string>

class ClapTrap {

  private:
    std::string name;
    int hitPoints = 10;
    int energyPoints = 10;
    int atackDamage = 0;

  public:
    ClapTrap(void);
    ~ClapTrap(void);

    void attack(const std::string& target);
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);
};

#endif
