#include "ClapTrap.hpp"

int main()
{
	std::string trap1 = "T1";
	std::string trap2 = "T2";
	std::string trap3 = "T3";

	ClapTrap clapTrap1(trap1);
	ClapTrap clapTrap2(trap2);
	ClapTrap clapTrap3(clapTrap2);
	clapTrap3 = clapTrap1;
 
	clapTrap1.Attack(trap2);
	clapTrap1.DisplayStatus();

	clapTrap2.TakeDamage(10);
	clapTrap2.TakeDamage(10);

	clapTrap1.TakeDamage(3);
	clapTrap1.BeRepaired(10);

	for(int i = 0; i < 10; i++)
		clapTrap1.Attack(trap2);
	clapTrap1.DisplayStatus();
	return (0);
} 