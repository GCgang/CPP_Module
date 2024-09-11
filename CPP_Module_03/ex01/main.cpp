#include "ScavTrap.hpp"

int main()
{
	ScavTrap scavTrap1;
	ScavTrap scavTrap2("scavTrap2"); 
	ScavTrap scavTrap3(scavTrap2);
	scavTrap3 = scavTrap1;

	scavTrap1.Attack("scavTrap2");
	scavTrap1.DisplayStatus();
	scavTrap2.TakeDamage(SCAV_ATTAK_DAMAGE);
	scavTrap2.BeRepaired(5);
	scavTrap2.GuardGate();
	std::cout << std::endl;
	return (0);
}