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
		// > < >= <= == !=
		bool operator>(const Fixed& other) const;
		bool operator<(const Fixed& other) const;
		bool operator>=(const Fixed& other) const;
		bool operator<=(const Fixed& other) const;
		bool operator==(const Fixed& other) const;
		bool operator!=(const Fixed& other) const;
		// + - * /
		Fixed operator+(const Fixed& other) const;
		Fixed operator-(const Fixed& other) const;
		Fixed operator*(const Fixed& other) const;
		Fixed operator/(const Fixed& other) const;
		// ++ --
		Fixed& operator++(void);
		Fixed operator++(int);
		Fixed& operator--(void);
		Fixed operator--(int);
		int GetRawBits(void) const;
		void SetRawBits(int const raw);
        int ToInteger(void) const;
        float ToFloat(void) const;
		static Fixed& min(Fixed& fixedPointNum1, Fixed& fixedPointNum2);
		static const Fixed& min(const Fixed& fixedPointNum1, const Fixed& fixedPointNum2);
		static Fixed& max(Fixed& fixedPoinNum1, Fixed& fixedPointNum2);
		static const Fixed& max(const Fixed& fixedPointNum1, const Fixed& fixedPointNum2);

	private:
		int mFixedPoint;
		static const int mFractionalBit = 8;
};

std::ostream& operator<<(std::ostream &out, const Fixed &other);

#endif	// FIXED_HPP