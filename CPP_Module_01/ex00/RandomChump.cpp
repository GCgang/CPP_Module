#include "Zombie.hpp"

void    RandomChump(std::string name)
{
    Zombie  stackZombie;

    stackZombie.SetName(name);
    stackZombie.Announce();
}
