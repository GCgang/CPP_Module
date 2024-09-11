#pragma once
#ifndef ICE_HPP
#define ICE_HPP

#include "AMateria.hpp"

class Ice : public AMateria
{
	public:
		Ice();
		Ice(const Ice& ice);
		Ice& operator=(const Ice& ice);
		virtual ~Ice();
		virtual AMateria* Clone() const;
		virtual void Use(ICharacter& target);
};

#endif // ICE_HPP