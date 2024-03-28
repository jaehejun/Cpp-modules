#include "Animal.hpp"
#include "Brain.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int main()
{

    // create and fill an array of Animal objects.
    // half Dog obj, half Cat obj,
    // at the end of program execution,
    // loop over this array and delete every Animal.
    // must delete directly dogs and cats as animals.
    // copy of a dog/cat mustn't be shallow
    // have to test copies are deep copies

    // const Animal *j = new Dog();
    // const Animal *i = new Cat();

    // delete j; // should not create a leak
    // delete i;

    // std::cout << "@@@@@@@@@@@@@@@ More Tests @@@@@@@@@@@@@@@@" << std::endl;

    Animal *animals[10];
    for (int i = 0; i < 10 / 2; i++)
    {
        animals[i] = new Dog();
    }

    for (int i = 10 / 2; i < 10; i++)
    {
        animals[i] = new Cat();
    }

    for (int i = 0; i < 10; i++)
    {
        delete animals[i];
    }

    // std::cout << "@@@@@@@@@@@@@@@ More Tests @@@@@@@@@@@@@@@@" << std::endl;
    // Brain a;
    // a.setIdea("hi");
    // a.getIdeas();

    // Dog b;
    // b.setIdea("hello");
    // b.setIdea("bye");
    // b.getIdeas();

    // Dog copy(b);
    // copy.setIdea("copied");
    // copy.getIdeas();

    // std::cout << "@@@@@@@@@@@ORIGINAL@@@@@@@@@@@" << std::endl;
    // b.getIdeas();

    // return 0;
}