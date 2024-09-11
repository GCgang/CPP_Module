#include <iostream>
#include "Fixed.hpp"

int main( void )
{
	Fixed a;
	Fixed b( a );
	Fixed c;

	c = b;
	std::cout << a.GetRawBits() << std::endl;
	std::cout << b.GetRawBits() << std::endl;
	std::cout << c.GetRawBits() << std::endl;
	return 0;
}