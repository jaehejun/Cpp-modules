#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int main()
{
	DiamondTrap a("A");
	a.whoAmI();
	a.show();
	a.attack("A");
	a.takeDamage(30);

	DiamondTrap b(a);
	b.whoAmI();
	b.show();
	b.attack("A");
	a.takeDamage(30);

	DiamondTrap c("C");
	c = a;
	c.whoAmI();
	c.show();
	c.attack("A");
	a.takeDamage(30);
	a.show();


	return 0;
}