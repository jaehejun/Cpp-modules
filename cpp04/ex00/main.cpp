#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
    const Animal *meta = new Animal();
    meta->makeSound();
    std::cout << meta->getType() << " " << std::endl;
	std::cout << "META: " << meta << std::endl;

	//const Animal *copyMeta = new Animal(*meta);
	//copyMeta->makeSound();
    //std::cout << copyMeta->getType() << " " << std::endl;
	//std::cout << "Copy: " << copyMeta << std::endl;

	//Animal *assignMeta = new Animal();
	//*assignMeta = *meta;
	//assignMeta->makeSound();
    //std::cout << assignMeta->getType() << " " << std::endl;
	//std::cout << "Assign: " << assignMeta << std::endl;

    Animal *j = new Dog();
	j->makeSound();
    std::cout << j->getType() << " " << std::endl;

    const Animal *i = new Cat();
    i->makeSound(); // will output the cat sound!
    std::cout << i->getType() << " " << std::endl;


	const WrongAnimal *w = new WrongCat();
	w->makeSound();
	//delete meta;
	//delete copyMeta;
	//delete assignMeta;

	delete meta;
	delete j;
	delete i;
	delete w;


	Dog a;
	Dog b(a);
	b.makeSound();
    std::cout << b.getType() << " " << std::endl;
	Dog c;
	c = a;
	c.makeSound();
    std::cout << c.getType() << " " << std::endl;


    return 0;
}