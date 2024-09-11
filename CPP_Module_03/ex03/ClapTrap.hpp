#pragma once
#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>
#define CLAP_TRAP_NAME "ClapTrap"
#define CLAP_HIT_POINT (10)
#define CLAP_ENERGY_POINT (10)
#define CLAP_ATTAK_DAMAGE (0)

class ClapTrap
{
	public:
		ClapTrap(); 
		ClapTrap(std::string name);
		ClapTrap(ClapTrap& other);
		ClapTrap& operator=(ClapTrap& other);
		virtual ~ClapTrap();
		virtual void	Attack(const std::string& target);
		void	TakeDamage(unsigned int amount);
		void	BeRepaired(unsigned int amount);
		virtual void	DisplayStatus(void) const;
	protected:
		std::string mName;
		unsigned int mHealth;
		unsigned int mEnergyPoint;
		unsigned int mAttackDamage;
		static const unsigned int MIN_ENERGY_POINT = 0;
		static const unsigned int MAX_HIT_POINT = 100;
		static const unsigned int MAX_ENERGY_POINT = 10;
		static const unsigned int ZERO_HIT_POINT = 0;
	private:
		static const  std::string mDefaultName;
		static const unsigned int mDefaultHitPoint = CLAP_HIT_POINT;
		static const unsigned int mDefaultEnergyPoint = CLAP_ENERGY_POINT;
		static const unsigned int mDefaultAttackDamage = CLAP_ATTAK_DAMAGE;
};

#endif