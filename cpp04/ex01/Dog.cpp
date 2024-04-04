#include "Animal.hpp"
#include "Dog.hpp"
#include "Brain.hpp"

Dog::Dog() : Animal("Dog")
{
    std::cout << "Dog constructor called" << std::endl;
    brain = new Brain();
}

Dog::Dog(const Dog &other) : Animal(other)
{
    std::cout << "Dog copy constructor called" << std::endl;
    brain = new Brain(*(other.brain));
}

////얕은 복사 생성자
//Dog::Dog(const Dog &other) : Animal(other), brain(other.brain)
//{
//    std::cout << "Dog SHALLOW copy constructor called" << std::endl;
//}

Dog::~Dog()
{
    std::cout << "Dog destructor called" << std::endl;
    delete brain;
}

Dog &Dog::operator=(const Dog &other)
{
    std::cout << "Dog assignment operator called" << std::endl;
    if (this != &other)
    {
        Animal::operator=(other);
        delete brain;
        brain = new Brain(*(other.brain));
    }
    return *this;
}

////얕은 복사 대입 연산자 오버로딩
//Dog &Dog::operator=(const Dog &other)
//{
//    std::cout << "Dog SHALLOW assignment operator called" << std::endl;
//    if (this != &other)
//    {
//        Animal::operator=(other);
//        brain = other.brain;
//    }
//    return *this;
//}

void Dog::makeSound() const
{
    std::cout << "WOOF" << std::endl;
}

void Dog::setIdea(const std::string &idea)
{
    brain->setIdea(idea);
}

void Dog::getIdeas()
{
    brain->getIdeas();
}