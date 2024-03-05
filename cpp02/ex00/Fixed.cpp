#include "Fixed.hpp"

// 왜 static은 빼고 써야되지
const int Fixed::fractionalBits = 8;

Fixed::Fixed() : value(0)
{
    std::cout << "Default constructor called" << std::endl;
}

// 왜 const 붙여야하지
// subject의 출력순서를 맞추기 위해서 복사생성자에서 대입연산자 오버로딩 함수를 사용.
Fixed::Fixed(const Fixed &fixed)
{
    std::cout << "Copy constructor called" << std::endl;
	*this = fixed;
}

// 왜 자기자신을 return 해야하지
// 복사생성자를 호출하는 것과 무슨 차이가 있지
// 왜 const 붙여야하지
// subject의 출력순서를 맞추기 위해서 getRawBits()메서드를 호출
Fixed &Fixed::operator=(const Fixed &fixed)
{
    std::cout << "Copy assignment operator called" << std::endl;
	value = fixed.getRawBits();
	return *this;
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