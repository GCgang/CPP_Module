#include "FragTrap.hpp"

const std::string FragTrap::mDefaultName = FRAG_TRAP_NAME;

FragTrap::FragTrap()
	: ClapTrap()
{
	mName = FragTrap::mDefaultName;
	mHealth = FragTrap::mDefaultHitPoint;
	mEnergyPoint = FragTrap::mDefaultEnergyPoint;
	mAttackDamage = FragTrap::mDefaultAttackDamage;
	std::cout << "FragTrap created" << std::endl;
	DisplayStatus();
}

FragTrap::FragTrap(std::string name)
	: ClapTrap(name)
{
	mName = name;
	mHealth = FragTrap::mDefaultHitPoint;
	mEnergyPoint = FragTrap::mDefaultEnergyPoint;
	mAttackDamage = FragTrap::mDefaultAttackDamage;
	std::cout << "FragTrap created" << std::endl;
	DisplayStatus();
}

FragTrap::FragTrap(FragTrap& other)
	: ClapTrap(other)
{
	std::cout << "FragTrap Copy constructor called" << std::endl;
	this->mName = other.mName;
	this->mHealth = other.mHealth;
	this->mEnergyPoint = other.mEnergyPoint;
	this->mAttackDamage = other.mAttackDamage;
	DisplayStatus();
}

FragTrap& FragTrap::operator=(FragTrap& other)
{
	if (this != &other)
	{
		ClapTrap::operator=(other);
		this->mName = other.mName;
		this->mHealth = other.mHealth;
		this->mEnergyPoint = other.mEnergyPoint;
		this->mAttackDamage = other.mAttackDamage;
	}
	std::cout << "FragTrap Copy assignment operator caled"  << std::endl;
	DisplayStatus();
	return (*this);
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap Destructor called" << std::endl;

}

void	FragTrap::Attack(const std::string& target)
{
	if (mHealth <= ZERO_HIT_POINT)
	{
		std::cout << mDefaultName;
		std::cout << " is already dead " << std::endl;
		return ;
	}
	else if (mEnergyPoint <= MIN_ENERGY_POINT)
	{
		std::cout << mDefaultName;
		std::cout << " Not enough energy! Attack requires 1 energy point " << std::endl;
		return ;
	}
	mEnergyPoint--;
	std::cout << mDefaultName;
	std::cout << " attacks " << target;
	std::cout << ", causing " << mDefaultAttackDamage << " points of damage!" << std::endl;
}

void	FragTrap::DisplayStatus(void) const
{
	std::cout << "+-----------------STATUS------------------+" << std::endl;
	std::cout << "Name : " << mName << std::endl;
	std::cout << "Health : " << mHealth << std::endl;
	std::cout << "EnergyPoint : " << mEnergyPoint << std::endl;
	std::cout << "AttackDamage : " << mAttackDamage << std::endl;
	std::cout << "+-----------------------------------------+" << std::endl;
	std::cout << std::endl;
}

void FragTrap::HighFivesGuys(void) const
{
	std::cout << mName;
	std::cout << " Give me some highfives, guys" << std::endl;
}