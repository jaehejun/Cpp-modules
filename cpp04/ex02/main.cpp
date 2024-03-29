#include "Animal.hpp"
#include "Brain.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int main()
{
    //Animal a;
    Dog dog;
    Cat cat;

    std::cout << dog.getType() << std::endl;
    dog.makeSound();
    std::cout << cat.getType() << std::endl;
    cat.makeSound();

    dog.setIdea("Dog's idea");
    cat.setIdea("Cat's idea");

    std::cout << "DOG : ";
    dog.getIdeas();
    std::cout << "CAT : ";
    cat.getIdeas();

    Dog copyDog(dog);
    copyDog.setIdea("Copy's idea");
    std::cout << "COPY DOG : ";
    copyDog.getIdeas();

    std::cout << "OG DOG after copied : ";
    dog.getIdeas();
}