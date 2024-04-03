#include "AMateria.hpp"

AMateria::AMateria()
{
    std::cout << "AMateria default constructor called" << std::endl;
}

AMateria::AMateria(std::string const &type) : type(type), isEquiped(false)
{
    std::cout << "AMateria constructor with [" << type << "] TYPE called" << std::endl;
}

AMateria::AMateria(const AMateria &other) : type(other.type), isEquiped(other.isEquiped)
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
    if (this != &other)
    {
        if (type != other.type)
        {
            std::cout << "Type doesn't match!" << std::endl;
        }
        isEquiped = other.isEquiped;
    }
    return *this;
}

std::string const &AMateria::getType() const
{
    return type;
}

void AMateria::use(ICharacter &target)
{
    std::cout << "AMateria use() called" << std::endl;
    (void)target;
}

bool AMateria::getStatus() const
{
    return isEquiped;
}

void AMateria::setStatus()
{
    isEquiped = !isEquiped;
}