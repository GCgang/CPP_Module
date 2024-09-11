#pragma once
#ifndef CURE_HPP
#define CURE_HPP

#include "AMateria.hpp"

class Cure : public AMateria
{
	public:
		Cure();
		Cure(const Cure& cure);
		Cure& operator=(const Cure& cure);
		virtual ~Cure();
		virtual AMateria* Clone() const;
		virtual void Use(ICharacter& target);
};

#endif // CURE_HPP