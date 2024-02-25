#include "Zombie.hpp"

int main()
{
    Zombie stackZombie();
    stackZombie.randomChump("stackZombie");

    Zombie *heapZombie = newZombie("heapZombie");

    return 0;
}