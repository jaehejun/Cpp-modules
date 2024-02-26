#include "Zombie.hpp"

int main()
{
    Zombie mainScopeZombie("mainScopeZombie");
    mainScopeZombie.announce();

    randomChump("stackZombie");

    Zombie *heapZombie = newZombie("heapZombie");
    if (heapZombie == NULL)
    {
        return 0;
    }
    heapZombie->announce();

    delete heapZombie;

    return 0;
}