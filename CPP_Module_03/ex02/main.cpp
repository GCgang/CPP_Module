#include "FragTrap.hpp"

int main()
{
	FragTrap fragTrap1;
	FragTrap fragTrap2("fragTrap2"); 
	FragTrap fragTrap3(fragTrap2);
	fragTrap3 = fragTrap1;

	fragTrap1.Attack("fragTrap2");
	fragTrap1.DisplayStatus();
	fragTrap2.TakeDamage(FRAG_ATTAK_DAMAGE);
	fragTrap2.BeRepaired(5);
	fragTrap2.HighFivesGuys();
	std::cout << std::endl;
	return (0);
}