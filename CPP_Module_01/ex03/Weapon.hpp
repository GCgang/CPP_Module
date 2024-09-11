#pragma once
#ifndef WEAPON_HPP
# define WEAPON_HPP

#include <iostream>
#include <string>

class Weapon
{
	public:
		Weapon();
		Weapon(std::string weaponType);
		~Weapon();
		const std::string& GetType(void) const;
		void	SetType(const std::string &type);
	private:
		std::string mType;
};

#endif // WEAPON_HPP