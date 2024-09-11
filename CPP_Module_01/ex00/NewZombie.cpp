#include "Zombie.hpp"

Zombie* NewZombie(std::string name)
{
    Zombie* heapZombie = new Zombie();
    heapZombie->SetName(name);
	heapZombie->Announce();

    return (heapZombie);
}