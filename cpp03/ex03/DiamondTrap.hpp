#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include <iostream>
#include <string>

class DiamondTrap : public ClapTrap, public ScavTrap, public FragTrap
{
  private:
	std::string name;
    DiamondTrap();

  public:
    DiamondTrap(std::string name);
    DiamondTrap(const DiamondTrap &diamondTrap);
    ~DiamondTrap();

    DiamondTrap &operator=(const DiamondTrap &diamondTrap);

    void whoAmI();
};

#endif