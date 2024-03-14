#include "ClapTrap.hpp"
#include "FragTrap.hpp"

int main()
{
	FragTrap a("A");
	a.highFivesGuys();
	a.takeDamage(10);
	
	FragTrap b("B");
	b.highFivesGuys();
	b.attack("BATTACK WHO");
	
	FragTrap c = a;
	//FragTrap c(a);
	
	//c.attack("CATTA");


	FragTrap d("D");
	d = b;
	
	//d.attack("DATTB");
	//d.takeDamage(100);
	//d.beRepaired(100);

	FragTrap z(d);
	//z.attack("Z");
	
	return 0;
}