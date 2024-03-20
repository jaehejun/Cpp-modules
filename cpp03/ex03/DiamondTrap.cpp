#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap()
{
	std::cout << "Default constuctor called from DiamondTrap" << std::endl;
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name), name(name)
{
	std::cout << "Constructor called from DiamondTrap " << name << std::endl;
	hitPoints = FragTrap::fragHitPoints;
	energyPoints = ScavTrap::scavEnergyPoints;
	attackDamage = FragTrap::fragAttackDamage;
}

DiamondTrap::DiamondTrap(const DiamondTrap& diamondTrap) : ClapTrap(diamondTrap), ScavTrap(diamondTrap), FragTrap(diamondTrap), name(diamondTrap.name)
{
	std::cout << "Copy constructor called with DiamondTrap " << name << std::endl;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "Destructor called from DiamondTrap " << name << std::endl;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& diamondTrap)
{
	std::cout << "Copy assignment operator called with DiamondTrap " << name << std::endl;
	if (this != &diamondTrap)
	{
		ScavTrap::operator=(diamondTrap);
		name = diamondTrap.name;
	}
	return *this;
}

void DiamondTrap::whoAmI()
{
	std::cout << "DiamondTrap name: " << name << std::endl;
	std::cout << "ClapTrap name: " << ClapTrap::name << std::endl;
}

void DiamondTrap::show()
{
	std::cout << "Name: " << name << std::endl;
	std::cout << "CLAP: " << ClapTrap::name << std::endl;
	std::cout << "HP: " << hitPoints << std::endl;
	std::cout << "EP: " << energyPoints << std::endl;
	std::cout << "AD: " << attackDamage << std::endl;
}