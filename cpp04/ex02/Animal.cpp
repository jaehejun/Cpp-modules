#include "Animal.hpp"

Animal::Animal() : type("Animal")
{
    std::cout << "Animal constructor called" << std::endl;
}

Animal::Animal(const std::string &type) : type(type)
{
	std::cout << "Animal constructor with TYPE called" << std::endl;
}

Animal::Animal(const Animal &other) : type(other.type)
{
    std::cout << "Animal copy constructor called" << std::endl;
}

Animal::~Animal()
{
    std::cout << "Animal destructor called" << std::endl;
}

Animal &Animal::operator=(const Animal &other)
{
	std::cout << "Animal assignment operator called" << std::endl;
	if (this != &other)
	{
		type = other.type;
	}
	return *this;
}

void Animal::makeSound() const
{
	std::cout << "Animal sound" << std::endl;
}

void Animal::setType(const std::string &type)
{
	this->type = type;
}

std::string Animal::getType() const
{
	return type;
}