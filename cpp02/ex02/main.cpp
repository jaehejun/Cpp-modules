#include <iostream>
#include "Fixed.hpp"

int main(void)
{
    //Fixed a;
    Fixed const b(Fixed(2.0f) * Fixed(4));
    //std::cout << a << std::endl;
    //std::cout << ++a << std::endl;
    //std::cout << a << std::endl;
    //std::cout << a++ << std::endl;
    //std::cout << a << std::endl;
    //std::cout << b << std::endl;
    //std::cout << Fixed::max(a, b) << std::endl;
    std::cout << "BEFORE MAIN" << std::endl;
    return 0;
}

/*

$> ./a.out
0
0.00390625
0.00390625
0.00390625
0.0078125
10.1016
10.1016
$>

*/