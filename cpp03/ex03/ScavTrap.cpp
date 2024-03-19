#include "ScavTrap.hpp"

const unsigned int ScavTrap::scavEnergyPoints = 50;

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
	std::cout << "Destructor called from ScavTrap " << name << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& scavTrap) : ClapTrap(scavTrap)
{
	std::cout << "Copy constructor called with ScavTrap " << name << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& scavTrap)
{
	std::cout << "Copy assignment operator called with ScavTrap " << name << std::endl;
	if (this != &scavTrap)
	{
		ClapTrap::operator=(scavTrap);
	}
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
    std::cout << "ScavTrap " << name << " attacks " << target << ", causing " << attackDamage << " points of damage!"
              << std::endl;
    energyPoints -= 1;
}