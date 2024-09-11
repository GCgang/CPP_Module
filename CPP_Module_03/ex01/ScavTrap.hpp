#pragma once
#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"
#define SCAV_TRAP_NAME "ScavTrap"
#define SCAV_HIT_POINT (100)
#define SCAV_ENERGY_POINT (50)
#define SCAV_ATTAK_DAMAGE (20)

class ScavTrap : virtual public ClapTrap
{
	public:
		ScavTrap();
		ScavTrap(std::string name);
		ScavTrap(ScavTrap& other);
		ScavTrap& operator=(ScavTrap& other);
		virtual ~ScavTrap();
		virtual void	Attack(const std::string& target);
		virtual void	DisplayStatus(void) const;
		void	GuardGate(void) const;
	protected:
		static const std::string mDefaultName; 
		static const unsigned mDefaultHitPoint = SCAV_HIT_POINT;
		static const unsigned mDefaultEnergyPoint = SCAV_ENERGY_POINT;
		static const unsigned mDefaultAttackDamage = SCAV_ATTAK_DAMAGE;
};

#endif