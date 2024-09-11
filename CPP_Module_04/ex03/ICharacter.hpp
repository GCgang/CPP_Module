#pragma once
#ifndef ICHARACTER_HPP
#define ICHARACTER_HPP

#include <iostream>
class AMateria;

class ICharacter
{
	public:
		virtual ~ICharacter() {}
		virtual std::string const & GetName() const = 0;
		virtual void Equip(AMateria* m) = 0;
		virtual void UnEquip(int idx) = 0;
		virtual void Use(int idx, ICharacter& target) = 0;
};

#endif // ICHARACTER_HPP