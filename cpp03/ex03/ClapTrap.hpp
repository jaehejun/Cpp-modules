#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>
#include <string>

class ClapTrap
{
  protected:
    std::string name;
    int hitPoints;
    unsigned int energyPoints;
    unsigned int attackDamage;
    ClapTrap();

  public:
    ClapTrap(std::string name);
    ClapTrap(const ClapTrap &clapTrap);
    virtual ~ClapTrap();

    ClapTrap &operator=(const ClapTrap &clapTrap);

    virtual void attack(const std::string &target);
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);
};

#endif