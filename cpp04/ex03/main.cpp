#include "AMateria.hpp"
#include "Character.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "MateriaSource.hpp"
#include <cstdlib>

void leakCheck()
{
	system("leaks AMateria");
}

int main()
{
	atexit(leakCheck);

	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	src->learnMateria(new Cure());
	src->learnMateria(new Cure());

	src->learnMateria(new Cure());
	ICharacter* me = new Character("me");
	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);


	tmp = src->createMateria("ice");
	me->equip(tmp);
	delete tmp;

	ICharacter* bob = new Character("bob");
	me->use(0, *bob);
	me->use(1, *bob);
	me->use(2, *bob);
	me->use(3, *bob);

	me->unequip(0);
	me->unequip(1);

	tmp = src->createMateria("fire");
	tmp = src->createMateria("cure");
	bob->equip(tmp);
	bob->use(0, *me);
	bob->unequip(0);

	me->equip(tmp);

	delete bob;
	delete me;
	delete src;
	std::cout << "@@@@@@@@@@@@@@@@CLEARING THE FLOOR@@@@@@@@@@@@@@@@@" << std::endl;
	Character::clearFloor();

	return 0;
}