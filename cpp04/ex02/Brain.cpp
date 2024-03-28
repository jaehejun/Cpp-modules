#include "Brain.hpp"

Brain::Brain()
{
    std::cout << "Brain constructor called" << std::endl;
}

Brain::Brain(const Brain &other)
{
    std::cout << "Brain copy constructor called" << std::endl;
    for (int i = 0; i < 100; i++)
    {
        ideas[i] = other.ideas[i];
    }
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
        for (int i = 0; i < 100; i++)
        {
            ideas[i] = other.ideas[i];
        }
    }
    return *this;
}

void Brain::setIdea(const std::string &idea)
{
    for (int i = 0; i < 100; i++)
    {
        if (ideas[i].empty())
        {
            ideas[i] = idea;
            break;
        }
    }
}

void Brain::getIdeas() const
{
    for (int i = 0; i < 100; i++)
    {
        if (ideas[i].empty())
            break;
        std::cout << "ideas[" << i << "]: " << ideas[i] << std::endl;
    }
}