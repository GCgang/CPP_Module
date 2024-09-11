#include "Ice.hpp"

Ice::Ice()
	: AMateria("ice")
{
	std::cout << "Ice default constructor" << std::endl;
	mType = "ice";	
}

Ice::Ice(const Ice& ice)
	: AMateria(ice)
{
	std::cout << "Ice copy constructor" << std::endl;
	mType = ice.GetType();
}

Ice& Ice::operator=(const Ice& ice)
{
	std::cout << "Ice assignation operator" << std::endl;
	if (this != &ice)
	{
		AMateria::operator=(ice);
		mType = ice.GetType();
	}
	return (*this);
}

Ice::~Ice()
{
	std::cout << "Ice destructor" << std::endl;
}

AMateria* Ice::Clone() const
{
	AMateria* clonedIce = new Ice(*this);

	std::cout << "Ice Materia cloned. Returning a new Ice Materia" << std::endl;
	
	return (clonedIce);
}

void Ice::Use(ICharacter& target)
{
	std::cout << "* shoots an ice bolt at ";
	std::cout << target.GetName() << " *" << std::endl;
}