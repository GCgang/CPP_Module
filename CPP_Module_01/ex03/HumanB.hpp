#pragma once
#ifndef HUMANB_HPP
# define HUMANB_HPP

#include <iostream>
#include <string>
#include "Weapon.hpp"

class HumanB
{
	public:
		HumanB();
		HumanB(std::string name);
		~HumanB();
		void	SetWeapon(Weapon& club);
		void	Attack() const;
	private:
		std::string mName;
		Weapon* mWeapon;
};

#endif // HUMANB_HPP