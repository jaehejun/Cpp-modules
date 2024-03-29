#include "Character.hpp"

Character::Character()
{
	std::cout << "Character default constructor called" << std::endl;
}

Character::Character(const Character &other) : name(other.name)
{
	std::Cout << "Character copy constructor called" << std::endl;
}

Character::~Character()
{
	std::cout << "Character default destructor called" << std::endl;
}

Character &Character::operator=(const Character &other)
{
	std::cout << "Character assignment operator called" << std::endl;
}

std::string const &Character::getName() const
{
	return name;
}

virtual void Character::equip(AMateria *m)
{
	m;
}

virtual void Character::unequip(int idx)
{
	slot[idx]
}

virtual void Character::use(int idx, ICharacter &target)
{
	if (target.slot[idx].type == ice)
        std::cout << "* shoots an ice bolt at " << target.name << " " << std::endl;
	if (target.slot[idx].type == cure)
        std::cout << "* heals " << target.name << "'s  wounds *" << std::endl;
}