#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
    std::cout << "Default Constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : name(name), hitPoints(10), energyPoints(10), attackDamage(0)
{
    std::cout << "Constructor called from " << name << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &clapTrap) : name(clapTrap.name), hitPoints(clapTrap.hitPoints), energyPoints(clapTrap.energyPoints), attackDamage(clapTrap.attackDamage)
{
    std::cout << "Copy constructor called with " << name << std::endl;
}

ClapTrap::~ClapTrap()
{
    std::cout << "Destructor called from " << name << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &clapTrap)
{
    std::cout << "Copy assignment operator called with " << clapTrap.name << std::endl;
    name = clapTrap.name;
    hitPoints = clapTrap.hitPoints;
    energyPoints = clapTrap.energyPoints;
    attackDamage = clapTrap.attackDamage;
    return *this;
}

void ClapTrap::attack(const std::string &target)
{
    if (hitPoints <= 0)
    {
        std::cout << "ClapTrap " << name << " seems to be dead..." << std::endl;
        return;
    }
    if (energyPoints <= 0)
    {
        std::cout << "ClapTrap " << name << " has not enough energy points for attacking!" << std::endl;
        return;
    }
    std::cout << "ClapTrap " << name << " attacks " << target << ", casuing " << attackDamage << " points of damage!"
              << std::endl;
    energyPoints -= 1;
}

void ClapTrap::takeDamage(unsigned int amount)
{
    if (hitPoints <= 0)
    {
        std::cout << "ClapTrap " << name << " is already dead!" << std::endl;
        return;
    }
    std::cout << "ClapTrap " << name << " takes " << amount << " of damage!" << std::endl;
    hitPoints -= amount;
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (hitPoints <= 0)
    {
        std::cout << "ClapTrap " << name << " seems to be dead..." << std::endl;
        return;
    }
    if (energyPoints <= 0)
    {
        std::cout << "ClapTrap " << name << " has not enough energy points for repairing!" << std::endl;
        return;
    }
    std::cout << "ClapTrap " << name << " repairs " << amount << " of hit points back!" << std::endl;
    energyPoints -= 1;
    hitPoints += amount;
}