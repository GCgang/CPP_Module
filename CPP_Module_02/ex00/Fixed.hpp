#pragma once
#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed
{
	public:
		Fixed();
		Fixed(const Fixed& other);
		Fixed& operator=(const Fixed& other);
		~Fixed();
		int GetRawBits(void) const;
		void SetRawBits(int const raw);
	private:
		int mFixedPoint;
		static const int mFractionalBit = 8;
};

#endif	// FIXED_HPP