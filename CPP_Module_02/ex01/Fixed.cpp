#include "Fixed.hpp"

Fixed::Fixed()
    : mFixedPoint(0)
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int integer)
    : mFixedPoint(integer * (1 << mFractionalBit))
{
    std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float floatingPointNumber)
	: mFixedPoint(static_cast<int>(roundf(floatingPointNumber * static_cast<float>((1 << mFractionalBit)))))
{
    std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& other)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = other;
}

Fixed& Fixed::operator=(const Fixed &other)
{
    std::cout << "Copy assignment operator caled"  << std::endl;
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
    return (mFixedPoint);   
}

void Fixed::SetRawBits(int const raw)
{
    mFixedPoint = raw;
}

int Fixed::ToInteger(void) const
{
    return (mFixedPoint / (1 << mFractionalBit));
}  

float Fixed::ToFloat(void) const
{
	return ((static_cast<float>(mFixedPoint)) / (static_cast<float>(1 << mFractionalBit)));
}

std::ostream& operator<<(std::ostream &out, const Fixed &other)
{
	out << other.ToFloat();
	return (out);
}
