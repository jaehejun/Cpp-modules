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

// 6개의 비교 연산자 오버로딩
bool Fixed::operator>(const Fixed &other) const
{
    return fixedValue > other.fixedValue;
}
bool Fixed::operator<(const Fixed &other) const
{
    return fixedValue < other.fixedValue;
}
bool Fixed::operator>=(const Fixed &other) const
{
    return fixedValue >= other.fixedValue;
}
bool Fixed::operator<=(const Fixed &other) const
{
    return fixedValue <= other.fixedValue;
}
bool Fixed::operator==(const Fixed &other) const
{
    return fixedValue == other.fixedValue;
}
bool Fixed::operator!=(const Fixed &other) const
{
    return fixedValue != other.fixedValue;
}

// 4개의 산술 연산자 오버로딩
Fixed Fixed::operator+(const Fixed &other) const
{
    Fixed result;
    result.fixedValue = fixedValue + other.fixedValue;
    return result;
}
Fixed Fixed::operator-(const Fixed &other) const
{
    Fixed result;
    result.fixedValue = fixedValue - other.fixedValue;
    return result;
}
Fixed Fixed::operator*(const Fixed &other) const
{
    Fixed result;
    result.fixedValue = (fixedValue * other.fixedValue) >> fractionalBits;
    return result;
}
Fixed Fixed::operator/(const Fixed &other) const
{
    Fixed result;
    result.fixedValue = (fixedValue << fractionalBits) / other.fixedValue;
    return result;
}


// 4개의 증가/감소 연산자 오버로딩
Fixed& Fixed::operator++()
{
    fixedValue += 1;
    return *this;
}
Fixed Fixed::operator++(int)
{
    Fixed temp(*this);
    fixedValue += 1;
    return temp;
}
Fixed &Fixed::operator--()
{
    fixedValue -= 1;
    return *this;
}
Fixed Fixed::operator--(int)
{
    Fixed temp(*this);
    fixedValue -= 1;
    return temp;
}

// 정적 멤버 함수 min/max 오버로딩
Fixed& Fixed::min(Fixed &a, Fixed &b)
{
    return a.fixedValue < b.fixedValue ? a : b;
}
const Fixed& Fixed::min(const Fixed &a, const Fixed &b)
{
    return a.fixedValue < b.fixedValue ? a : b;
}
Fixed& Fixed::max(Fixed &a, Fixed &b)
{
    return a.fixedValue > b.fixedValue ? a : b;
}
const Fixed& Fixed::max(const Fixed &a, const Fixed &b)
{
    return a.fixedValue > b.fixedValue ? a : b;
}

// operator <<
std::ostream &operator<<(std::ostream &outStream, const Fixed &fixed)
{
    float printNumber = fixed.toFloat();
    outStream << printNumber;
    return outStream;
}