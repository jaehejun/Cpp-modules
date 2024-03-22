#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "Brain default ㅡㅁconstructor called" << std::endl;
}

Brain::Brain(const Brain &other)
{
	std::cout << "Brain copy constructor called" << std::endl;
	(void)other;
}

Brain::~Brain()
{
	std::cout << "Brain destructor called" << std::endl;
}

Brain &Brain::operator=(const Brain &other)
{
	std::cout << "Brain assignment operator called" << std::endl;
	if (this != &other)
	{
		;
	}
	return *this;
}