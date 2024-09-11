#include <iostream>
#include "Fixed.hpp"

int main( void )
{
    Fixed a;
    Fixed const b( 10 );
    Fixed const c( 42.42f );
    Fixed const d( b );
    a = Fixed( 1234.4321f );

    std::cout << "a is " << a << std::endl;
    std::cout << "b is " << b << std::endl;
    std::cout << "c is " << c << std::endl;
    std::cout << "d is " << d << std::endl;
    std::cout << "a is " << a.ToInteger() << " as integer" << std::endl;
    std::cout << "b is " << b.ToInteger() << " as integer" << std::endl;
    std::cout << "c is " << c.ToInteger() << " as integer" << std::endl;
    std::cout << "d is " << d.ToInteger() << " as integer" << std::endl;

    return (0);
}