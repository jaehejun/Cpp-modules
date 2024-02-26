#include "Zombie.hpp"
#include <iostream>

Zombie *newZombie(std::string name)
{
    Zombie *newZombie = new (std::nothrow) Zombie(name);

    if (newZombie == NULL)
    {
        std::cout << "Failed to allocate memory!" << std::endl;
        return NULL;
    }

    return newZombie;
}

// return new Zombie(name); 으로만 쓸 수도 있음