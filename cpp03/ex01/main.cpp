#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

void Cry(Animal* animal)
{
 	animal->cry();
}

void Cry(Dog* dog)
{
 	dog->cry();
}

void Cry(Cat* cat)
{
 	cat->cry();
}

class Animal
{
	cry()
	{
		"CRY"
	}
}

class Cat
{
	cry()
	{
		"meow"
	}
}

int main()
{

	Animal *a = new Cat("cat"); 
	Animal *b = new Dog("dog"); 
	Animal *c = new hotdug("hyung"); 

	Cry(a);


	a->cry;  meow
	b->cry;  bark
	c->cry;  yammy

	cat.cry
	dog.cry
	hotdog.cry

	//ClapTrap* a = new ScavTrap("A");
	
	//a->attack("ATTACK");
	//delete a;

	//ScavTrap a("A");
	//a.guardGate();
	//a.attack("B");
	////a.takeDamage(10);
	//a.guardGate();

	//ScavTrap b("B");
	//b.guardGate();
	
	//ScavTrap c = a;
	//c = b;
	////ScavTrap c(a);
	//c.attack("CATTA");

	//ScavTrap d("D");
	//d = b;
	//d.attack("DATTB");
	////d.takeDamage(100);
	////d.beRepaired(100);

	//ScavTrap z(d);
	//z.attack("Z");
	
	return 0;
}