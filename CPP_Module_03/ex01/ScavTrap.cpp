#include "ScavTrap.hpp"

const std::string ScavTrap::mDefaultName = SCAV_TRAP_NAME;

ScavTrap::ScavTrap()
	: ClapTrap()
{
	mName = ScavTrap::mDefaultName;
	mHealth = ScavTrap::mDefaultHitPoint;
	mEnergyPoint = ScavTrap::mDefaultEnergyPoint;
	mAttackDamage = ScavTrap::mDefaultAttackDamage;
	std::cout << "ScavTrap created" << std::endl;
	DisplayStatus();
}

ScavTrap::ScavTrap(std::string name)
	: ClapTrap(name)
{
	mName = name;
	mHealth = ScavTrap::mDefaultHitPoint;
	mEnergyPoint = ScavTrap::mDefaultEnergyPoint;
	mAttackDamage = ScavTrap::mDefaultAttackDamage;
	std::cout << "ScavTrap created" << std::endl;
	DisplayStatus();
}

ScavTrap::ScavTrap(ScavTrap& other)
	: ClapTrap(other)
{
	std::cout << "ScavTrap Copy constructor called" << std::endl;
	this->mName = other.mName;
	this->mHealth = other.mHealth;
	this->mEnergyPoint = other.mEnergyPoint;
	this->mAttackDamage = other.mAttackDamage;
	DisplayStatus();
}

ScavTrap& ScavTrap::operator=(ScavTrap& other)
{
	if (this != &other)
	{
		ClapTrap::operator=(other);
		this->mName = other.mName;
		this->mHealth = other.mHealth;
		this->mEnergyPoint = other.mEnergyPoint;
		this->mAttackDamage = other.mAttackDamage;
	}
	std::cout << "ScavTrap Copy assignment operator caled"  << std::endl;
	DisplayStatus();
	return (*this);
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap Destructor called" << std::endl;
}

void	ScavTrap::Attack(const std::string& target)
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

void	ScavTrap::DisplayStatus(void) const
{
	std::cout << "+-----------------STATUS------------------+" << std::endl;
	std::cout << "Name : " << mName << std::endl;
	std::cout << "Health : " << mHealth << std::endl;
	std::cout << "EnergyPoint : " << mEnergyPoint << std::endl;
	std::cout << "AttackDamage : " << mAttackDamage << std::endl;
	std::cout << "+-----------------------------------------+" << std::endl;
	std::cout << std::endl;
}

void	ScavTrap::GuardGate(void) const
{
	std::cout << mName;
	std::cout << " Gate Keeper Mode ON" << std::endl;
}