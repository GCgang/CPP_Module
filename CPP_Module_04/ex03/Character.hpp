#pragma once
#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "AMateria.hpp"
#include "ICharacter.hpp"

class Character : public ICharacter
{
	public:
		Character();
		Character(const std::string& name);
		Character(const Character& character);
		Character& operator=(const Character& character);
		virtual ~Character();
		virtual std::string const& GetName() const;
		virtual void Equip(AMateria* materia);
		virtual void UnEquip(int idx);
		virtual void Use(int idx, ICharacter& target);
	private:
		static const int MAX_SLOT = 4;
		AMateria* mInventory[MAX_SLOT];
		std::string mName;
};

#endif // CHARACTER_HPP