#include "Zombie.hpp"

Zombie *zombieHorde(int N, std::string name)
{
    Zombie *zombieHorde = new (std::nothrow) Zombie[N];
    if (zombieHorde == NULL)
    {
        std::cout << "Failed to allocate memory!" << std::endl;
        return NULL;
    }
    for (int index = 0; index < N; index++)
        zombieHorde[index].setName(name);

    return zombieHorde;
}