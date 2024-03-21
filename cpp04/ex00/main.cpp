#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int main()
{
    //const Animal *meta = new Animal();
    //meta->makeSound();
    //std::cout << meta->getType() << " " << std::endl;
	//std::cout << "META: " << meta << std::endl;

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

    //const Animal *i = new Cat();
    //std::cout << i->getType() << " " << std::endl;
    //i->makeSound(); // will output the cat sound!
    //j->makeSound();

	//delete meta;
	//delete copyMeta;
	//delete assignMeta;

	delete j;
    return 0;
}