#include "Zombie.hpp"

int main()
{
	Zombie *hordeOfZombies = zombieHorde(5, "moarBrains");

	if (hordeOfZombies == NULL)
		return 0;

	for (int index = 0; index < 5; index++)
		hordeOfZombies[index].announce();

	delete [] hordeOfZombies;

	return 0;
}