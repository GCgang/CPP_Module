#pragma once
#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <iostream>
#include <string>

class Zombie
{
    public:
        Zombie();
        ~Zombie();
        void        Announce(void) const;
        void        SetName(std::string name);
        std::string GetName(void) const;
    private:
        std::string mName;
};

Zombie*     NewZombie(std::string name);
void        RandomChump(std::string name);

#endif // ZOMBIE_HPP