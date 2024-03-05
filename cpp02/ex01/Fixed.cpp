#include "Fixed.hpp"

const int Fixed::fractionalBits = 8;

Fixed::Fixed() : value(0)
{
    std::cout << "Default constructor called" << std::endl;
}

// intNum 의 비트를 왼쪽으로 8비트만큼 이동시킨다. 2^8인 256을 곱하는것과 같음
// 정수를 소수점이 없는 고정 소수점 값으로 변환한다
Fixed::Fixed(const int intNum) : value(intNum << fractionalBits)
{
    std::cout << "Int constructor called" << std::endl;
    // intNum -> fixedvalue
}

Fixed::Fixed(const float floatNum) : value(roundf(floatNum * (1 << fractionalBits)))
{
    std::cout << "Float constructor called" << std::endl;
    //floatNum->fixedValue
}

Fixed::Fixed(const Fixed &fixed)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = fixed;
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const
{
    std::cout << "getRawBits member function called" << std::endl;
    return (value);
}

void Fixed::setRawBits(int const raw)
{
    value = raw;
}

float Fixed::toFloat(void) const
{
    //value->floating point value
    return (float)value / (1 << fractionalBits);
}

int Fixed::toInt(void) const
{
    //value -> integer value
    return value >> fractionalBits;
}

Fixed &Fixed::operator=(const Fixed &fixed)
{
    std::cout << "Copy assignment operator called" << std::endl;
    value = fixed.value;
    return *this;
}

//std::ostream& Fixed::operator<<(std::ostream& outStream, const value& number)
//{
//    float printNumber = number.toFloat();
//    outStream << printNumber;
//    return outStream;

//    value -> floating-point value;
//    std::cout << floating-point value number
//}