#pragma once
#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"
#define FRAG_TRAP_NAME "FragTrap"
#define FRAG_HIT_POINT (100)
#define FRAG_ENERGY_POINT (100)
#define FRAG_ATTAK_DAMAGE (30)

class FragTrap : virtual public ClapTrap
{
	public:
		FragTrap();
		FragTrap(std::string name);
		FragTrap(FragTrap& other);
		FragTrap& operator=(FragTrap& other);
		virtual ~FragTrap();
		virtual void	Attack(const std::string& target);
		virtual void	DisplayStatus(void) const;
		void HighFivesGuys(void) const;
	protected:
		static const std::string mDefaultName; 
		static const unsigned int mDefaultHitPoint = FRAG_HIT_POINT;
		static const unsigned int mDefaultEnergyPoint = FRAG_ENERGY_POINT;
		static const unsigned int mDefaultAttackDamage = FRAG_ATTAK_DAMAGE;
};

#endif