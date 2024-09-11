#include "Zombie.hpp"

Zombie::Zombie()
	: mName("No Name")
{
}

Zombie::~Zombie()
{
	std::cout << GetName() << " destroyed" << std::endl;
}

void	Zombie::Announce() const
{
	std::cout << GetName() << " : " <<  "BraiiiiiiinnnzzzZ..." << std::endl;
}

void	Zombie::SetName(std::string name)
{
	mName = name;
}

std::string	Zombie::GetName() const
{
	return (mName);
}
