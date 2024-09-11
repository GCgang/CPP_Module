#include "Zombie.hpp"

Zombie* ZombieHorde(int zobieCount, std::string name)
{
	Zombie *zombieHorde = new Zombie[zobieCount];
	std::stringstream stringStream;
	std::string numberString;
	
	for (int index = 0; index < zobieCount; index++)
	{
		stringStream.str("");
		stringStream << index;
		numberString = stringStream.str();
		zombieHorde[index].SetName(name + numberString);
		// zombieHorde[index].SetName(name + std::to_string(index)); // c11
	}
	return (zombieHorde);
}