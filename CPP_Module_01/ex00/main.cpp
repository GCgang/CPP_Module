#include <iostream>
#include "Zombie.hpp"

// void	leaks(void)
// {
// 	system("leaks zombie");
// }

int main()
{
	// atexit(leaks);
	Zombie* heapZombie;
	heapZombie = NewZombie("Heap Zombie");

	RandomChump("Stack Zombie");
	delete heapZombie;
	return (0);
}