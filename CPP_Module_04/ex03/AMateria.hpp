#pragma once
#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include "ICharacter.hpp"
#include <iostream>

class AMateria
{
	public:
		AMateria();
		AMateria(std::string const & type);
		AMateria(const AMateria& aMateria);
		AMateria& operator=(const AMateria& aMateria);
		virtual ~AMateria();
		std::string const & GetType() const;
		virtual AMateria* Clone() const = 0;
		virtual void Use(ICharacter& target);
	protected:
		std::string mType;
};

#endif // AMATERIA_HPP