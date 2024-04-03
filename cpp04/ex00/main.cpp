#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include <cstdlib>

void leakCheck()
{
	system("leaks Polymorphism");
}

int main()
{
	atexit(leakCheck);

	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();

	delete meta;
	delete j;
	delete i;

	std::cout << "@@@@@@@@@@@@@@WRONG ONES@@@@@@@@@@@@@@@@" << std::endl;

	const WrongAnimal* wrongAnimal = new WrongAnimal();
	const WrongAnimal* wrongCat = new WrongCat();
	std::cout << wrongCat->getType() << " " << std::endl;
	wrongCat->makeSound(); //will output the cat sound!
	wrongAnimal->makeSound();

	delete wrongAnimal;
	delete wrongCat;


	return 0;
}