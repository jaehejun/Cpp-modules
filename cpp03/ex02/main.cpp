#include "ClapTrap.hpp"
#include "FragTrap.hpp"

int main()
{
	FragTrap a("A");
	a.highFivesGuys();
	
	FragTrap b("B");
	b.highFivesGuys();

	b.attack("A");
	a.takeDamage(30);
	b.attack("A");
	a.takeDamage(30);
	b.attack("A");
	a.takeDamage(30);
	
	FragTrap c(a);
	c.highFivesGuys();

	FragTrap d("D");
	d = c;
	d.highFivesGuys();
		
	b.attack("C");
	c.takeDamage(30);
	c.beRepaired(100);

	b.attack("D");
	d.takeDamage(30);
	d.beRepaired(100);

	
	return 0;
}