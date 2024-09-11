#include "Zombie.hpp"

// void	leaks(void)
// {
// 	system("leaks zombiehorde");
// }

int main()
{
	// atexit(leaks);
	Zombie* zombieHorde;

	zombieHorde = ZombieHorde(ZOMBIE_COUNT, "zombie");
	for (int index = 0; index < ZOMBIE_COUNT; index++)
	{
		zombieHorde[index].Announce();
	}
	delete[] zombieHorde;
	return (0);
}