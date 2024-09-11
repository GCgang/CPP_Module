#include <iostream>
#include <string>
#include "Whatever.hpp"

int main(void)
{
    int a = 2;
    int b = 3;
    Utility::swap(a, b);
    std::cout << "a = " << a << ", b = " << b << std::endl;
    std::cout << "min( a, b ) = " << Utility::min(a, b) << std::endl;
    std::cout << "max( a, b ) = " << Utility::max(a, b) << std::endl;
	std::cout << std::endl;

    std::string c = "chaine1";
    std::string d = "chaine2";
    Utility::swap(c, d);
    std::cout << "c = " << c << ", d = " << d << std::endl;
    std::cout << "min( c, d ) = " << Utility::min(c, d) << std::endl;
    std::cout << "max( c, d ) = " << Utility::max(c, d) << std::endl;
	std::cout << std::endl;

    float e = 3.14;
    float f = 2.71;
    Utility::swap(e, f);
    std::cout << "e = " << e << ", f = " << f << std::endl;
    std::cout << "min( e, f ) = " << Utility::min(e, f) << std::endl;
    std::cout << "max( e, f ) = " << Utility::max(e, f) << std::endl;
	std::cout << std::endl;

    char g = 'x';
    char h = 'y';
    Utility::swap(g, h);
    std::cout << "g = " << g << ", h = " << h << std::endl;
    std::cout << "min( g, h ) = " << Utility::min(g, h) << std::endl;
    std::cout << "max( g, h ) = " << Utility::max(g, h) << std::endl;
	std::cout << std::endl;
	
    return 0;
}
