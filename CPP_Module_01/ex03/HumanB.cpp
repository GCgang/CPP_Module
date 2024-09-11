#include "Weapon.hpp"
#include "HumanB.hpp"

HumanB::HumanB()
	: mName("No Name")
	, mWeapon(NULL)
{
}

HumanB::HumanB(std::string name)
	: mName(name)
	, mWeapon(NULL)
{
}

HumanB::~HumanB()
{
}

void	HumanB::SetWeapon(Weapon& club)
{
	mWeapon = &club;
}

void	HumanB::Attack() const
{
	std::cout << mName
			  <<  " attacks with their "
			  << ((mWeapon != NULL) ? mWeapon->GetType() : "FIST")
			  << std::endl; 
}