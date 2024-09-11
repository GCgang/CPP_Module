#include "AMateria.hpp"

AMateria::AMateria()
	: mType("AMateria")
{
	std::cout << "AMateria default constructor" << std::endl;
}

AMateria::AMateria(std::string const& type)
	: mType(type)
{
	std::cout << "AMateria default constructor with type" << std::endl;
}

AMateria::AMateria(const AMateria& aMateria)
	: mType(aMateria.GetType())
{
	std::cout << "AMateria copy constructor" << std::endl;
}

AMateria& AMateria::operator=(const AMateria& aMateria)
{
	std::cout << "AMateria assignation operator" << std::endl;
	if (this != &aMateria)
	{
		mType = aMateria.GetType();
	}
	return (*this);
}

AMateria::~AMateria()
{
	std::cout << "AMateria destructor" << std::endl;
}

std::string const& AMateria::GetType() const
{
	return (mType);
}

void AMateria::Use(ICharacter& target)
{
	std::cout << "* performs an action with AMateria on ";
	std::cout << target.GetName() << " *" << std::endl;
}
