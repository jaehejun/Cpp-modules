#include "Zombie.hpp"

Zombie::Zombie()
{
    std::cout << "Zombie created" << std::endl;
}

Zombie::~Zombie()
{
    std::cout << name << " destroyed!" << std::endl;
}

void Zombie::announce()
{
    std::cout << name << " :  BraiiiiiiinnnzzzZ..." << std::endl;
}