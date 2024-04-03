#include "Animal.hpp"
#include "Brain.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include <cstdlib>

void leakCheck()
{
    system("leaks Brain");
}

int main()
{
    atexit(leakCheck);

    const Animal *j = new Dog();
    const Animal *i = new Cat();

    delete j; // should not create a leak
    delete i;


    std::cout << "@@@@@@@@@@@@@@@ Dogs in ANIMAL ARRAY @@@@@@@@@@@@@@@@" << std::endl;
    Animal *animals[10];
    for (int i = 0; i < 10 / 2; i++)
    {
        animals[i] = new Dog();
    }

    std::cout << "@@@@@@@@@@@@@@@ Cats in ANIMAL ARRAY @@@@@@@@@@@@@@@@" << std::endl;
    for (int i = 10 / 2; i < 10; i++)
    {
        animals[i] = new Cat();
    }

    std::cout << "@@@@@@@@@@@@@@@ DELETE ANIMALS @@@@@@@@@@@@@@@@" << std::endl;
    for (int i = 0; i < 10; i++)
    {
        delete animals[i];
    }

    std::cout << "@@@@@@@@@@@@@@@ More Tests @@@@@@@@@@@@@@@@" << std::endl;

    Dog *a = new Dog();
    a->setIdea("hello");
    a->setIdea("bye");
    a->getIdeas();
    
    Dog *copy = new Dog(*a);
    copy->setIdea("COPIED!");
    copy->getIdeas();

    Dog *assign = new Dog();
    assign->setIdea("ASSIGNED!");
    assign->getIdeas();
    *assign = *copy;
    assign->getIdeas();

    delete a;
    delete copy;
    delete assign;

    std::cout << "@@@@@@@@@@@ORIGINAL@@@@@@@@@@@" << std::endl;

    return 0;
}