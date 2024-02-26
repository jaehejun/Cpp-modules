#include "Zombie.hpp"

void randomChump(std::string name)
{
    Zombie randomChumpZombie(name);
    randomChumpZombie.announce();
}