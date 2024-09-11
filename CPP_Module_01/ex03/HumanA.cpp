#include "Weapon.hpp"
#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon& weaponREF)
	: mName(name)
	, mWeaponREF(weaponREF)
{
}

HumanA::~HumanA()
{
}

void	HumanA::Attack() const
{
	std::cout << mName
			  << " attacks with their "
			  << mWeaponREF.GetType()
			  << std::endl;
}