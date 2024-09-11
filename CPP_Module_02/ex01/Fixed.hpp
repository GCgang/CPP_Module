#pragma once
#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <cmath>

class   Fixed
{
    public:
        Fixed();
        Fixed(const int integer);
        Fixed(const float floatingPointNumber);
        Fixed(const Fixed& other);
        Fixed& operator=(const Fixed& other);
        ~Fixed();
		int GetRawBits(void) const;
		void SetRawBits(int const raw);
        int ToInteger(void) const;
        float ToFloat(void) const;
	private:
		int mFixedPoint;
		static const int mFractionalBit = 8;
};

std::ostream& operator<<(std::ostream &out, const Fixed &other);

#endif	// FIXED_HPP