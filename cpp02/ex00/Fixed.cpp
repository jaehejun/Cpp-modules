#include "Fixed.hpp"

Fixed::static const int fractionalBits = 8;

Fixed::Fixed() : fixedPointNumberValue(0)
{
	std::cout << "Default constructor called" << std::endl;
}

copy_cons
Fixed::Fixed(Fixed &fixed)
{
	std::cout << "Copy constructor called" << std::endl;
}

copy_assignmnet operator
{
	std::cout << "Copy assignment operator called" << std::endl;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	
	return (raw value of the fixed-point value);
}

void Fixed::setRawBits(int const raw)
{
	sets the raw value of the fixed-point number
}