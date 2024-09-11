#include "DiamondTrap.hpp"

const std::string DiamondTrap::mDefaultName = DIAMOND_TRAP_NAME;

DiamondTrap::DiamondTrap()
	: ClapTrap(static_cast<std::string>(CLAP_TRAP_NAME) + static_cast<std::string>("_clap_name"))
	, ScavTrap(static_cast<std::string>(SCAV_TRAP_NAME) + static_cast<std::string>("_clap_name"))
	, FragTrap(static_cast<std::string>(FRAG_TRAP_NAME) + static_cast<std::string>("_clap_name"))
{
	mName = DiamondTrap::mDefaultName;
	mHealth = FragTrap::mDefaultHitPoint;
	mEnergyPoint = ScavTrap::mDefaultEnergyPoint;
	mAttackDamage = FragTrap::mDefaultAttackDamage;
    std::cout << "DiamondTrap created" << std::endl;
	DisplayStatus();
}

DiamondTrap::DiamondTrap(std::string name)
	: ClapTrap(name + static_cast<std::string>("_clap_name"))
	, ScavTrap(name + static_cast<std::string>("_clap_name"))
	, FragTrap(name + static_cast<std::string>("_clap_name"))
{
	mName = name;
	mHealth = FragTrap::mDefaultHitPoint;
	mEnergyPoint = ScavTrap::mDefaultEnergyPoint;
	mAttackDamage = FragTrap::mDefaultAttackDamage;
	std::cout << "DiamondTrap created" << std::endl;
	DisplayStatus();
}

DiamondTrap::DiamondTrap(DiamondTrap& other)
	: ClapTrap(other)
	, ScavTrap(other)
	, FragTrap(other)
{
	std::cout << "DiamondTrap Copy constructor called" << std::endl;
	this->mName = other.mName;
	this->mHealth = other.mHealth;
	this->mEnergyPoint = other.mEnergyPoint;
	this->mAttackDamage = other.mAttackDamage;
	DisplayStatus();
}

DiamondTrap& DiamondTrap::operator=(DiamondTrap& other)
{
	if (this != &other)
	{
		ClapTrap::operator=(other);
		ScavTrap::operator=(other);
		FragTrap::operator=(other);
		this->mName = other.mName;
		this->mHealth = other.mHealth;
		this->mEnergyPoint = other.mEnergyPoint;
		this->mAttackDamage = other.mAttackDamage;
	}
	std::cout << "DiamondTrap Copy assignment operator caled"  << std::endl;
	DisplayStatus();
	return (*this);
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap Destructor called" << std::endl;
}

void DiamondTrap::Attack(const std::string& target)
{
	ScavTrap::Attack(target);
}

void DiamondTrap::DisplayStatus(void) const
{
	std::cout << "+-----------------STATUS------------------+" << std::endl;
	std::cout << "Name : " << mName << std::endl;
	std::cout << "Health : " << mHealth << std::endl;
	std::cout << "EnergyPoint : " << mEnergyPoint << std::endl;
	std::cout << "AttackDamage : " << mAttackDamage << std::endl;
	std::cout << "+-----------------------------------------+" << std::endl;
	std::cout << std::endl;
}

void DiamondTrap::WhoAmI()
{
	std::cout << "ClapTrap : " << ClapTrap::mName << std::endl;
	std::cout << "DiamondTrap : " << mName << std::endl;
}