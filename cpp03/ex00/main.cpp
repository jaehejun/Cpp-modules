#include "ClapTrap.hpp"

int main()
{
	ClapTrap a("A");
	ClapTrap b("B");

	ClapTrap c(a);
	ClapTrap d(e);

	a.attack("B");
	b.takeDamage(9);
	b.beRepaired(1);
	b.takeDamage(10);

	b.beRepaired(1);
	b.attack("A");
	b.takeDamage(5);

	a.takeDamage(5);
	a.beRepaired(5);

	a.attack("B");
	a.attack("B");
	a.attack("B");
	a.attack("B");
	a.attack("B");
	a.attack("B");
	a.attack("B");
	a.attack("B");
	a.attack("B");
	a.attack("B");
	a.beRepaired(10);

	return 0;
}