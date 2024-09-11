#include "Fixed.hpp"

Fixed::Fixed()
    : mFixedPoint(0)
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& other)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = other;
}

Fixed& Fixed::operator=(const Fixed& other)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other)
    {
		mFixedPoint = other.GetRawBits();
    }
    return (*this);
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

int Fixed::GetRawBits(void) const
{
    std::cout << "getRawBits member function called" << std::endl;
    return (mFixedPoint);   
}

void Fixed::SetRawBits(int const raw)
{
    mFixedPoint = raw;
}
