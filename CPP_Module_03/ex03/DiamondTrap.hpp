#pragma once
#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

#define DIAMOND_TRAP_NAME "DiamondTrap"

class DiamondTrap : public ScavTrap, public FragTrap
{
	public:
		DiamondTrap();
		DiamondTrap(std::string name);
		DiamondTrap(DiamondTrap& other);
		DiamondTrap& operator=(DiamondTrap& other);
		virtual ~DiamondTrap();
		virtual void	Attack(const std::string& target);
		virtual void	DisplayStatus(void) const;
		void	WhoAmI();
	private:
		std::string mName;
		static const std::string mDefaultName; 

};

#endif 