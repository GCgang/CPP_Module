#pragma once
#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <iostream>
#include <string>
#include <sstream>

#define ZOMBIE_COUNT (5)
class Zombie
{
	public:
		Zombie();
		~Zombie();
		void		Announce(void) const;
		void		SetName(std::string name);
		std::string	GetName(void) const;
	private:
		std::string mName;
};

Zombie*		ZombieHorde(int zombieCount, std::string name);

#endif // ZOMBIE_HPP