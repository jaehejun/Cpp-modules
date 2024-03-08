#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
  private:
    int fixedValue;
    // 고정 소수점 숫자가 얼마나 많은 비트를 소수 부분에 할당하지 결정하는 매개변수
    // 이 class에서는 32bit 중 8bit를 소수 부분이 차지한다
    // int type에 담긴 value의 값을 해석할 때 fractionalBits를 이용한다
    // -> 정수형 변수를 실수형 변수처럼 취급가능하게 한다
    static const int fractionalBits;

  public:
    Fixed();
    Fixed(const int intNum);
    Fixed(const float floatNum);
    Fixed(const Fixed &fixed);
    ~Fixed();

    int getRawBits(void) const;
    void setRawBits(int const raw);
    float toFloat(void) const;
    int toInt(void) const;

    Fixed &operator=(const Fixed &fixed);
};

std::ostream& operator<<(std::ostream& outStream, const Fixed& fixed);

#endif