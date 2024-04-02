#include "Character.hpp"
#include "AMateria.hpp"

AMateria *Character::floor[10] = {NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL};

int Character::floorStorage = 0;

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
        delete slot[i];
        slot[i] = NULL;
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

Character::~Character()
{
    std::cout << "Character name [" << name << "] default destructor called" << std::endl;
	for (int i = 0; i < 4; i++)
	{
        if (slot[i] != NULL)
        {
		    delete slot[i];
            slot[i] = NULL;
        }
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
        {
        	std::cout << "slot[" << idx << "]" << "is empty!" << std::endl;
        }
		else
        {
            if (floorStorage < 10)
            {
                std::cout << "!!!!!!!!!!!!!!UNEQUIP SLOT[" << idx << "]:" << slot[idx]->getType() << " to floor[" << floorStorage<< "]!!!!!!!!!!!!!!!!" << std::endl;
                floor[floorStorage] = slot[idx];
                floorStorage += 1;
			    slot[idx] = NULL;
            }
            else
                std::cout << "Floor is full of Materias! Can't equip anymore!" << std::endl;
        }
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

void Character::clearFloor()
{
    for (int i = 0; i < 10; i++)
    {
        if (floor[i] != NULL)
        {
            std::cout << "!!!!!!!!!!!!CLEAR FLOOR[" << i << "]:" << floor[i]->getType() << "!!!!!!!!!!!!!!!!!" << std::endl;
            delete floor[i];
            floor[i] = NULL;
        }
    }
}