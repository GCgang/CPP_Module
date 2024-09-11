#include "ClapTrap.hpp"

const std::string ClapTrap::mDefaultName = CLAP_TRAP_NAME;

ClapTrap::ClapTrap()
	: mName(ClapTrap::mDefaultName)
	, mHealth(ClapTrap::mDefaultHitPoint)
	, mEnergyPoint(ClapTrap::mDefaultEnergyPoint)
	, mAttackDamage(ClapTrap::mDefaultAttackDamage)
{
    std::cout << "ClapTrap created" << std::endl;
	DisplayStatus();
}

ClapTrap::ClapTrap(std::string name)
	: mName(name)
	, mHealth(ClapTrap::mDefaultHitPoint)
	, mEnergyPoint(ClapTrap::mDefaultEnergyPoint)
	, mAttackDamage(ClapTrap::mDefaultAttackDamage)
{
	std::cout << "ClapTrap created" << std::endl;
	DisplayStatus();

}

ClapTrap::ClapTrap(ClapTrap& other)
	: mName(other.mName)
	, mHealth(other.mHealth)
	, mEnergyPoint(other.mEnergyPoint)
	, mAttackDamage(other.mAttackDamage)
{
    std::cout << "ClapTrap Copy constructor called" << std::endl;
	DisplayStatus();
}

ClapTrap& ClapTrap::operator=(ClapTrap& other)
{
	if (this != &other)
	{
		this->mName = other.mName;
		this->mHealth = other.mHealth;
		this->mEnergyPoint = other.mEnergyPoint;
		this->mAttackDamage = other.mAttackDamage;
	}
    std::cout << "ClapTrap Copy assignment operator caled"  << std::endl;
	DisplayStatus();
	return (*this);
}

ClapTrap::~ClapTrap()
{
    std::cout << "ClapTrap Destructor called" << std::endl;  
}

void	ClapTrap::Attack(const std::string& target)
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
	std::cout  << " attacks, " << target;
	std::cout << " causing " << mDefaultAttackDamage << " points of damage! " << std::endl;
	DisplayStatus();
}

void	ClapTrap::TakeDamage(unsigned int amount)
{
	if (mHealth <= ZERO_HIT_POINT)
	{
		std::cout <<  mName;
		std::cout << " is already dead " << std::endl;
		return ;
	}
	else if ((mHealth <= amount))
	{
		mHealth = ZERO_HIT_POINT;
		std::cout <<  mName;
		std::cout << " took " << amount;
		std::cout << " points of damage! ";
		std::cout << "Current health is " << mHealth << std::endl;
		std::cout << "ClapTrap " << mName;
		std::cout << " is dead " << std::endl;
		return ;
	}
	mHealth -= amount;
	std::cout <<  mName;
	std::cout << " took " << amount;
	std::cout << " points of damage! ";
	std::cout << "Current health is " << mHealth << std::endl;
	DisplayStatus();
}

void	ClapTrap::BeRepaired(unsigned int amount)
{
	if (mHealth <= ZERO_HIT_POINT)
	{
		std::cout <<  mName;
		std::cout << " is already dead " << std::endl;
		return ;
	}
	else if (mEnergyPoint <= MIN_ENERGY_POINT)
	{
		std::cout <<  mName;
		std::cout << " Not enough energy! Repair requires 1 energy point " << std::endl;
		return ;
	}
	else if (mHealth >= MAX_HIT_POINT)
	{
		std::cout <<  mName;
		std::cout << " health is already fully restored " << std::endl;
		std::cout << "No repairs needed " << std::endl;
		return ;
	}
	else if (mHealth + amount >= MAX_HIT_POINT)
	{
		mEnergyPoint--;
		mHealth = MAX_HIT_POINT;
		std::cout << mName;
		std::cout << " has been restored by " << amount;
		std::cout << " Current health is " << mHealth << std::endl;
		return ;
	}
	mEnergyPoint--;
	mHealth += amount;
	std::cout << mName;
	std::cout << " has been restored by " << amount;
	std::cout << " Current health is " << mHealth << std::endl;
	DisplayStatus();
}

void	ClapTrap::DisplayStatus(void) const
{
	std::cout << "+-----------------STATUS------------------+" << std::endl;
	std::cout << "Name : " << mName << std::endl;
	std::cout << "Health : " << mHealth << std::endl;
	std::cout << "EnergyPoint : " << mEnergyPoint << std::endl;
	std::cout << "AttackDamage : " << mAttackDamage << std::endl;
	std::cout << "+-----------------------------------------+" << std::endl;
	std::cout << std::endl;
}