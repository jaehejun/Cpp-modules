#include "Character.hpp"
#include "AMateria.hpp"

Character::Character()
{
    std::cout << "Character default constructor called" << std::endl;
}

Character::Character(const std::string &name) : name(name)
{
    std::cout << "Character constructor called with name [" << name << "]" << std::endl;
    for (int i = 0; i < 4; i++)
    {
        slot[i] = NULL;
    }
}

Character::Character(const Character &other) : name(other.name)
{
    std::cout << "Character copy constructor called" << std::endl;
    for (int i = 0; i < 4; i++)
    {
        if (other.slot[i])
            slot[i] = other.slot[i]->clone();
        else
            slot[i] = NULL;
    }
}

Character::~Character()
{
    std::cout << "Character name [" << name << "]default destructor called" << std::endl;
	for (int i = 0; i < 4; i++)
	{
		delete slot[i];
	}
}

Character &Character::operator=(const Character &other)
{
    std::cout << "Character assignment operator called" << std::endl;
	if (this != &other)
	{
    	name = other.name;
    	for (int i = 0; i < 4; i++)
    	{
			delete slot[i];
			if (other.slot[i])
			{
				slot[i] = other.slot[i]->clone();
			}
			else
			{
				slot[i] = NULL;
			}
	    }
	}
    return *this;
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
        if (slot[i] == NULL)
        {
            slot[i] = m;
            break;
        }
        if (i == 3)
        {
            std::cout << "slot is full!" << std::endl;
        }
    }
}

void Character::unequip(int idx)
{
    if (0 <= idx && idx <= 3)
    {
		if (slot[idx] == NULL)
        	std::cout << "slot[" << idx << "]" << "is empty!" << std::endl;
		else
    	// slot[idx] 를 비우기 전에 floor 에 보관해둬야 한다
			slot[idx] = NULL;
    }
}

void Character::use(int idx, ICharacter &target)
{
    if (0 <= idx && idx < 4 && slot[idx] != NULL)
    {
        slot[idx]->use(target);
    }
    else
    {
        std::cout << "There isn't any Materia in that slot!" << std::endl;
    }
}