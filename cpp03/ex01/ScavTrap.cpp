#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string name) : name(name), hitPoints(100), energyPoints(50), attackDamage(20)
{
	std::cout << "Constructor called from " << name << std::endl;
}

void ScavTrap::guardGate()
{
	std::cout << "ScavTrap is now in Gate keeper mode" << std::endl;
}