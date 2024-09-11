#pragma once
#ifndef HUMANA_HPP
# define HUMANA_HPP

#include <iostream>
#include <string>
#include "Weapon.hpp"

class HumanA
{
	public:
		HumanA(std::string name, Weapon& weaponREF);
		~HumanA();
		void	Attack() const;
	private:
		std::string mName;
		Weapon&	mWeaponREF;
};

#endif // HUMANA_HPP