#include "Ice.hpp"

Ice::Ice()
{
	std::cout << "Ice default constructor called" << std::endl;
}

Ice::Ice(const Ice &other)
{
	std::cout << "Ice copy constructor called" << std::endl;
}

Ice::~Ice()
{
	std::cout << "Ice destructor called" << std::endl;
}

Ice &Ice::operator=(const Ice &other)
{
	std::cout << "Ice assignment operator called" << std::endl;
}

Ice *Ice::clone() const
{
	return &Ice();
}