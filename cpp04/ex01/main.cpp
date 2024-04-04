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

    Dog *og = new Dog();
    og->setIdea("hello");
    og->setIdea("bye");
    std::cout << "@@@@@@@@@@@@@@@ OG's brain @@@@@@@@@@@@@@@@" << std::endl;
    og->getIdeas();
    
    Dog *copy = new Dog(*og);
    copy->setIdea("COPIED!");
    std::cout << "@@@@@@@@@@@@@@@ COPY's brain @@@@@@@@@@@@@@@@" << std::endl;
    copy->getIdeas();

    std::cout << "@@@@@@@@@@@@@@@ OG after Copy @@@@@@@@@@@@@@@@" << std::endl;
    og->getIdeas();

    Dog *assign = new Dog();
    assign->setIdea("ASSIGNED!");
    std::cout << "@@@@@@@@@@@@@@@ ASSIGN's brain @@@@@@@@@@@@@@@@" << std::endl;
    assign->getIdeas();

    *assign = *copy;
    assign->setIdea("Deep copy shouldn't share this idea");
    std::cout << "@@@@@@@@@@@@@@@ COPY after assign setIdea() @@@@@@@@@@@@@@@@" << std::endl;
    copy->getIdeas();
    std::cout << "@@@@@@@@@@@@@@@ ASSIGN after assign setIdea() @@@@@@@@@@@@@@@@" << std::endl;
    assign->getIdeas();

    delete og;
    delete copy;
    delete assign;

    return 0;
}