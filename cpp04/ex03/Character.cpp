#include "Character.hpp"
#include "AMateria.hpp"

Character::Character()
{
	std::cout << "Character default constructor called" << std::endl;
}

Character::Character(const std::string &name) : name(name), slots{NULL, NULL, NULL, NULL}
{
	std::cout << "Character constructor called with name" << std::endl;
}

Character::Character(const Character &other) : name(other.name), slots{NULL, NULL, NULL, NULL}
{
	std::cout << "Character copy constructor called" << std::endl;
	for (int i = 0; i < 4; i++)
	{
		if (other.slots[i])
			slots[i] = other.slots[i]->clone();
	}
}

Character::~Character()
{
	std::cout << "Character default destructor called" << std::endl;
}

Character &Character::operator=(const Character &other)
{
	std::cout << "Character assignment operator called" << std::endl;
	name = other.name;
	for (int i = 0; i < 4; i++)
	{
		if (slots[i])
		{
			unequip(i);
		}
		if (other.slots[i])
		{
			slots[i] = other.slots[i]->clone();
		}
	}
}

std::string const &Character::getName() const
{
	return name;
}

void Character::equip(AMateria *m)
{
	// m 를 floor에서 주웠다면 floor에서는 없애줘야 한다
	for (int i = 0; i < 4; i++)
	{
		if (slots[i] == NULL)
		{
			slots[i] = m;
		}
		else
		{
			std::cout << "slots are full!" << std::endl;
		}
	}
}

void Character::unequip(int idx)
{
	if (slots[idx] == NULL)
	{
		std::cout << "Slots[" << idx << "]" << "is empty!" << std::endl;
	}
	// slots[idx] 를 비우기 전에 floor 에 보관해둬야 한다
	slots[idx] = NULL;
}

void Character::use(int idx, ICharacter &target)
{
	if (target.slots[idx].type == "ice")
        AMateria::use(target);
	if (target.slots[idx].type == "cure")
		AMateria::use(target);
}