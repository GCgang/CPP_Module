#include "DiamondTrap.hpp"

int	main(void)
{
	DiamondTrap  diatrap1;
	DiamondTrap  diatrap2("diatrap2");
	DiamondTrap  diatrap3(diatrap2);
	diatrap3 = diatrap1;

	diatrap1.Attack("diatrap2");
	std::cout << std::endl;
	diatrap1.DisplayStatus();
	diatrap2.TakeDamage(SCAV_ATTAK_DAMAGE);
	diatrap2.BeRepaired(5);
	diatrap2.GuardGate();
	diatrap2.HighFivesGuys();
	diatrap2.WhoAmI();
	std::cout << std::endl;

	return (0);
}
