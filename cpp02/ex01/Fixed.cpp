#include "Fixed.hpp"

const int Fixed::fractionalBits = 8;

Fixed::Fixed() : fixedValue(0)
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int intNum) : fixedValue(intNum << fractionalBits)
{
    std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float floatNum) : fixedValue(roundf(floatNum * (1 << fractionalBits)))
{
    std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &fixed)
{
    std::cout << "Copy constructor called" << std::endl;
    fixedValue = fixed.getRawBits();
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const
{
    return fixedValue;
}

void Fixed::setRawBits(int const raw)
{
    fixedValue = raw;
}

float Fixed::toFloat(void) const
{
    return static_cast<float>(fixedValue) / (1 << fractionalBits);
}

int Fixed::toInt(void) const
{
    return fixedValue >> fractionalBits;
}

Fixed &Fixed::operator=(const Fixed &fixed)
{
    std::cout << "Copy assignment operator called" << std::endl;
    fixedValue = fixed.getRawBits();
    return *this;
}

std::ostream& operator<<(std::ostream& outStream, const Fixed& fixed)
{
     float printNumber = fixed.toFloat();
     outStream << printNumber;
     return outStream;
}