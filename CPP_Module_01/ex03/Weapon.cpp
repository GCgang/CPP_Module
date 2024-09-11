#include "Weapon.hpp"

Weapon::Weapon()
	: mType("FIST")
{
}

Weapon::Weapon(std::string weponType)
	:mType(weponType)
{
}

Weapon::~Weapon()
{
}

const std::string& Weapon::GetType(void) const
{
	return (mType);
}

void	Weapon::SetType(const std::string& type)
{
	mType = type;
}
