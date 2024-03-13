#include "FragTrap.hpp"

FragTrap::FragTrap()
{
	std::cout << "Default constructor called from FragTrap" << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	std::cout << "Constructor called from FragTrap " << name << std::endl;
	hitPoints = 100;
	energyPoints = 100;
	attackDamage = 30;
}

FragTrap::~FragTrap()
{
	std::cout << "Destructor called from FragTrap " << name << std::endl;
}

FragTrap::FragTrap(const FragTrap& FragTrap) : ClapTrap(FragTrap)
{
	std::cout << "Copy constructor called with FragTrap " << name << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& FragTrap)
{
	ClapTrap::operator=(FragTrap);
	std::cout << "Copy assignment operator called with FragTrap " << name << std::endl;
	return *this;
}

void FragTrap::highFivesGuys()
{
	std::cout << "High five!(positive) from FragTrap " << name << std::endl;
}