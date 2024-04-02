#include "AMateria.hpp"
#include "Character.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "MateriaSource.hpp"

//int main()
//{
//	AMateria *a = new Ice();
//	AMateria *b = new Cure();

//	Character j("jay");
//	Character h("hyung");

//	j.equip(a);
//	j.equip(b);

//	j.use(0, h);
//	j.use(1, h);

//	delete a;
//	delete b;
//}

int main()
{
	IMateriaSource* src = new MateriaSource();
	std::cout << "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@" << std::endl;
	src->learnMateria(new Ice());
	std::cout << "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@" << std::endl;
	src->learnMateria(new Cure());
	std::cout << "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@" << std::endl;
	ICharacter* me = new Character("me");
	std::cout << "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@" << std::endl;
	AMateria* tmp;
	std::cout << "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@" << std::endl;
	tmp = src->createMateria("ice");
	std::cout << "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@" << std::endl;
	me->equip(tmp);
	std::cout << "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@" << std::endl;
	tmp = src->createMateria("cure");
	std::cout << "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@" << std::endl;
	me->equip(tmp);
	std::cout << "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@" << std::endl;
	ICharacter* bob = new Character("bob");
	std::cout << "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@" << std::endl;
	me->use(0, *bob);
	std::cout << "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@" << std::endl;
	me->use(1, *bob);
	std::cout << "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@" << std::endl;


	//Character sam("sam");
	//sam.equip(tmp);
	//Character jay("jay");
	//jay = sam;
	//jay.use(0, *bob);

	//sam = jay;
	//sam.use(0, *me);

	//me->unequip(0);
	//me->unequip(1);

	//me->use(1, *bob);
	//me->equip(tmp);


	delete bob;
	std::cout << "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@" << std::endl;
	delete me;
	std::cout << "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@" << std::endl;
	delete src;
	std::cout << "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@" << std::endl;
	Character::clearFloor();
	return 0;
}

//int main()
//{
//	AMateria *ice;
//	AMateria *ice2;
//	AMateria *cure;
//	AMateria *cure2;
//	ice = new Ice();
//	cure = new Cure();

//	ice2 = ice->clone();
//	cure2 = cure->clone();

//	*ice = *cure;
//	*cure = *ice;
//	std::cout << "ICE TYPE : " << ice->getType() << std::endl;
//	std::cout << "CURE TYPE : " << cure->getType() << std::endl;
//	std::cout << "ICE2 TYPE : " << ice2->getType() << std::endl;
//	std::cout << "CURE2 TYPE : " << cure2->getType() << std::endl;

//	delete ice;
//	delete ice2;
//	delete cure;
//	delete cure2;
//}