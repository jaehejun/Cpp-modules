#include "AMateria.hpp"

AMateria::AMateria()
{
    std::cout << "AMateria default constructor called" << std::endl;
}

AMateria::AMateria(std::string const &type) : type(type)
{
    std::cout << "AMateria constructor with TYPE called" << std::endl;
}

AMateria::AMateria(const AMateria &other) : type(other.type)
{
    std::cout << "AMateria copy constructor called" << std::endl;
}

AMateria::~AMateria()
{
    std::cout << "AMateria destructor called" << std::endl;
}

AMateria &AMateria::operator=(const AMateria &other)
{
    std::cout << "AMateria assignment operator called" << std::endl;
    type = other.type;
}

std::string const &AMateria::getType() const
{
    return type;
}

void AMateria::use(ICharacter &target)
{
    if (Ice)
        std::cout << "* shoots an ice bolt at " << target.name << " " << std::endl;
    if (Cure)
        std::cout << "* heals " << target.name << "'s  wounds *" << std::endl;
}