#include "Fixed.hpp"

Fixed::Fixed()
    : mFixedPoint(0)
{
}

Fixed::Fixed(const int integer)
    : mFixedPoint(integer * (1 << mFractionalBit))
{
}

Fixed::Fixed(const float floatingPointNumber)
	: mFixedPoint(static_cast<int>(roundf(floatingPointNumber * static_cast<float>((1 << mFractionalBit)))))
{
}

Fixed::Fixed(const Fixed& other)
{
    *this = other;
}

Fixed::~Fixed()
{
}

Fixed& Fixed::operator=(const Fixed &other)
{
    if (this != &other)
    {
		mFixedPoint = other.GetRawBits();
    }
    return (*this);
}

bool Fixed::operator>(const Fixed& other) const
{
	Fixed	greater(*this);

	return (greater.GetRawBits() > other.GetRawBits() ? true : false);
};

bool Fixed::operator<(const Fixed& other) const
{
	Fixed	less(*this);

	return (less.GetRawBits() < other.GetRawBits() ? true : false);
};

bool Fixed::operator>=(const Fixed& other) const
{
	Fixed	greaterEqual(*this);

	return (greaterEqual.GetRawBits() >= other.GetRawBits() ? true : false);
};

bool Fixed::operator<=(const Fixed& other) const
{
	Fixed	lessEqual(*this);

	return (lessEqual.GetRawBits() <= other.GetRawBits() ? true : false);
};

bool Fixed::operator==(const Fixed& other) const
{
	Fixed	equal(*this);

	return (equal.GetRawBits() == other.GetRawBits() ? true : false);
};

bool Fixed::operator!=(const Fixed& other) const
{
	Fixed	notEqual(*this);

	return (notEqual.GetRawBits() != other.GetRawBits() ? true : false);
};

Fixed Fixed::operator+(const Fixed& other) const
{
	Fixed	sum(this->ToFloat() + other.ToFloat());

	return (sum);
};

Fixed Fixed::operator-(const Fixed& other) const
{
	Fixed	sub(this->ToFloat() - other.ToFloat());

	return (sub);
};

Fixed Fixed::operator*(const Fixed& other) const
{
	Fixed	mul(this->ToFloat() * other.ToFloat());

	return (mul);
};

Fixed Fixed::operator/(const Fixed& other) const
{
	if (other.ToFloat() == 0)
	{
		std::cout << "Error : Divided by zero ";
		return (Fixed());
	}
	Fixed	div(this->ToFloat() / other.ToFloat());

	return (div);
};

Fixed& Fixed::operator++(void)
{
	++mFixedPoint;
	return (*this);
};

Fixed Fixed::operator++(int)
{
	Fixed	postIncrement(*this);

	mFixedPoint++;
	return (postIncrement);
};

Fixed& Fixed::operator--(void)
{
	--mFixedPoint;
	return (*this);
}

Fixed Fixed::operator--(int)
{
	Fixed	postDecrement(*this);

	mFixedPoint--;
	return (postDecrement);
}

Fixed& Fixed::min(Fixed& fixedPointNum1, Fixed& fixedPointNum2)
{
	return (fixedPointNum1.GetRawBits() < fixedPointNum2.GetRawBits() ? fixedPointNum1 : fixedPointNum2);
}

const Fixed& Fixed::min(const Fixed& fixedPointNum1, const Fixed& fixedPointNum2)
{
	return (fixedPointNum1.GetRawBits() < fixedPointNum2.GetRawBits() ? fixedPointNum1 : fixedPointNum2);
}

Fixed& Fixed::max(Fixed& fixedPoinNum1, Fixed& fixedPointNum2)
{
	return (fixedPoinNum1.GetRawBits() > fixedPointNum2.GetRawBits() ? fixedPoinNum1 : fixedPointNum2);
}

const Fixed& Fixed::max(const Fixed& fixedPointNum1, const Fixed& fixedPointNum2)
{
	return (fixedPointNum1.GetRawBits() > fixedPointNum2.GetRawBits() ? fixedPointNum1 : fixedPointNum2);
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
