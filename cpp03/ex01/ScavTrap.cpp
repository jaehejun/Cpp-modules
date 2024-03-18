#include "ScavTrap.hpp"

ScavTrap::ScavTrap()
{
	std::cout << "Default constructor called from ScavTrap" << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	std::cout << "Constructor called from ScavTrap " << name << std::endl;
	hitPoints = 100;
	energyPoints = 50;
	attackDamage = 20;
}

ScavTrap::~ScavTrap()
{
	// delete memory
	std::cout << "Destructor called from ScavTrap " << name << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& scavTrap) : ClapTrap(scavTrap)
{
	std::cout << "Copy constructor called with ScavTrap " << name << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& scavTrap)
{
	ClapTrap::operator=(scavTrap);
	std::cout << "Copy assignment operator called with ScavTrap " << name << std::endl;
	return *this;
}

void ScavTrap::guardGate()
{
	std::cout << "ScavTrap " << name << " is now in Gate keeper mode" << std::endl;
}

void ScavTrap::attack(const std::string& target)
{
	if (hitPoints <= 0)
    {
        std::cout << "ScavTrap " << name << " seems to be dead..." << std::endl;
        return;
    }
    if (energyPoints <= 0)
    {
        std::cout << "ScavTrap " << name << " has not enough energy points for attacking!" << std::endl;
        return;
    }
    std::cout << "ScavTrap " << name << " attacks " << target << ", casuing " << attackDamage << " points of damage!"
              << std::endl;
    energyPoints -= 1;
}