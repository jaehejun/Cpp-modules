#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
  private:
    int fixedValue;
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