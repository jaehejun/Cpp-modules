#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main()
{
	ScavTrap a("A");
	a.guardGate();
	a.attack("B");
	//a.takeDamage(10);
	a.guardGate();
	
	ScavTrap b("B");
	b.guardGate();
	
	ScavTrap c = a;
	//ScavTrap c(a);
	c.attack("CATTA");

	ScavTrap d("D");
	d = b;
	d.attack("DATTB");
	//d.takeDamage(100);
	//d.beRepaired(100);

	ScavTrap z(d);
	z.attack("Z");
	
	return 0;
}