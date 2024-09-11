#include "Character.hpp"

Character::Character()
	: mName("No Name")
{
	std::cout << "Character default constructor" << std::endl;
	for (int idx = 0; idx < MAX_SLOT; idx++)
	{
		mInventory[idx] = NULL;
	}
}

Character::Character(const std::string& name)
	: mName(name)
{
	std::cout << "Character default constructor with name" << std::endl;
	for (int idx = 0; idx < MAX_SLOT; idx++)
	{
		mInventory[idx] = NULL;
	}
}

Character::Character(const Character& character)
	: mName(character.mName)
{
	std::cout << "Character copy constructor" << std::endl;
	for (int idx = 0; idx < MAX_SLOT; idx++)
	{
		mInventory[idx] = NULL;
	}
	for (int idx = 0; idx < MAX_SLOT; idx++)
	{
		if (character.mInventory[idx] != NULL)
		{
			mInventory[idx] = character.mInventory[idx]->Clone();
		}
	}
}

Character& Character::operator=(const Character& character)
{
	std::cout << "Character assignation operator" << std::endl;
	if (this != &character)
	{
		mName = character.mName;
		for (int idx = 0; idx < MAX_SLOT; idx++)
		{
			delete mInventory[idx];
			mInventory[idx] = NULL;
		}
		for (int idx = 0; idx < MAX_SLOT; idx++)
		{
			if (character.mInventory[idx] != NULL)
			{
				mInventory[idx] = character.mInventory[idx]->Clone();
			}
		}
	}
	return (*this);
}

Character::~Character()
{
	for (int idx = 0; idx < MAX_SLOT; idx++)
	{
		delete mInventory[idx];
		mInventory[idx] = NULL;
	}
	std::cout << "Character destructor" << std::endl;
}

std::string const& Character::GetName() const
{
	return (mName);
}

void Character::Equip(AMateria* materia)
{
	if (materia == NULL)
	{
		std::cerr << "Error: Cannot equip NULL materia" << std::endl;
		return ;
	}

	for (int idx = 0; idx < MAX_SLOT; idx++)
	{
		if (mInventory[idx] == NULL)
		{
			std::cout << "Equipped materia" << std::endl;
			mInventory[idx] = materia;
			return ;
		}
	}
	std::cerr << "Error: Character inventory is full" << std::endl;
}

void Character::UnEquip(int idx)
{
	if (idx < 0 || MAX_SLOT <= idx)
	{
		std::cerr << "Error: Invalid index" << std::endl;
		return ;
	}

	if (mInventory[idx] == NULL)
	{
		std::cerr << "Error: No materia equipped" << std::endl;
		return ;
	}
	std::cout << "Unequipped materia" << std::endl;
	mInventory[idx] = NULL;
}

void Character::Use(int idx, ICharacter& target)
{
	if (idx < 0 || MAX_SLOT <= idx)
	{
		std::cerr << "Error: Invalid index" << std::endl;
		return ;
	}

	if (mInventory[idx] == NULL)
	{
		std::cerr << "Error: No materia equipped" << std::endl;
		return ;
	}

	mInventory[idx]->Use(target);
}