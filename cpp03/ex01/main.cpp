#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main()
{
	ScavTrap a("A");
	a.guardGate();

	ScavTrap b("B");
	b.guardGate();


	b.attack("A");
	a.takeDamage(20);
	b.attack("A");
	a.takeDamage(20);
	b.attack("A");
	a.takeDamage(20);
	b.attack("A");
	a.takeDamage(20);

	ScavTrap c("C");
	c = a;
	c.guardGate();
	ScavTrap d(c);
	d.guardGate();

	b.attack("C");
	c.takeDamage(20);
	b.attack("C");
	c.takeDamage(20);

	b.attack("D");
	d.takeDamage(20);
	b.attack("D");
	d.takeDamage(20);

	a.beRepaired(20);
	
	b.attack("A");
	a.takeDamage(20);
	b.attack("A");
	a.takeDamage(20);

	a.beRepaired(20);
	
	b.attack("A");
	b.attack("A");
	b.attack("A");
	b.attack("A");
	b.attack("A");
	b.attack("A");
	b.attack("A");
	b.attack("A");
	b.attack("A");
	b.attack("A");
	b.attack("A");
	b.attack("A");
	b.attack("A");
	b.attack("A");
	b.attack("A");
	b.attack("A");
	b.attack("A");
	b.attack("A");
	b.attack("A");
	b.attack("A");
	b.attack("A");
	b.attack("A");
	b.attack("A");
	b.attack("A");
	b.attack("A");
	b.attack("A");
	b.attack("A");
	b.attack("A");
	b.attack("A");
	b.attack("A");
	b.attack("A");
	b.attack("A");
	b.attack("A");
	b.attack("A");
	b.attack("A");
	b.attack("A");
	b.attack("A");
	b.attack("A");
	b.attack("A");
	b.attack("A");
	b.attack("A");
	b.attack("A");


	return 0;
}