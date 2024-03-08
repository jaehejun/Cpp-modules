#include "Fixed.hpp"

const int Fixed::fractionalBits = 8;

Fixed::Fixed() : fixedValue(0)
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int intNum) : fixedValue(intNum << fractionalBits)
{
    std::cout << "Int constructor called" << std::endl;
    std::cout << this << ": " << fixedValue << std::endl;
}

Fixed::Fixed(const float floatNum) : fixedValue(roundf(floatNum * (1 << fractionalBits)))
{
    std::cout << "Float constructor called" << std::endl;
    std::cout << this << ": " << fixedValue << std::endl;
}

Fixed::Fixed(const Fixed &fixed)
{
    std::cout << "Copy constructor called" << std::endl;
    fixedValue = fixed.getRawBits();
    std::cout << this << ": " << fixed.getRawBits() << std::endl;
    std::cout << "copied: " << &fixed << std::endl;
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
    std::cout << this << ": " << fixedValue << std::endl;
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

std::ostream &operator<<(std::ostream &outStream, const Fixed &fixed)
{
    float printNumber = fixed.toFloat();
    outStream << printNumber;
    return outStream;
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
    std::cout << "OPERATOR BEGIN" << std::endl;
    Fixed result;
    result.fixedValue = (fixedValue * other.fixedValue) >> fractionalBits;
    std::cout << result.fixedValue << std::endl;
    std::cout << "OPERATOR ENDSS" << std::endl;
    std::cout << "RESULT: " << &result << std::endl;
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
    fixedValue += 1 << fractionalBits;
    return *this;
}
//Fixed Fixed::operator++(int)
//{
//    Fixed temp(*this);
//    fixedValue += 1 << fractionalBits;
//    return temp;
//}
Fixed &Fixed::operator--()
{
    fixedValue -= 1 << fractionalBits;
    return *this;
}
//Fixed Fixed::operator--(int)
//{
//    Fixed temp(*this);
//    fixedValue -= 1 << fractionalBits;
//    return temp;
//}
// 정적 멤버 함수 min/max 오버로딩
const Fixed& Fixed::min(const Fixed &a, const Fixed &b)
{
    return a.fixedValue < b.fixedValue ? a : b;
}
const Fixed& Fixed::max(const Fixed &a, const Fixed &b)
{
    return a.fixedValue > b.fixedValue ? a : b;
}