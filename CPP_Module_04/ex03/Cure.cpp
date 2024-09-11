#include "Cure.hpp"

Cure::Cure()
	: AMateria("cure")
{
	std::cout << "Cure default constructor" << std::endl;
	mType = "cure";
}

Cure::Cure(const Cure& cure)
	: AMateria(cure)
{
	std::cout << "Cure copy constructor" << std::endl;
	mType = cure.GetType();
}

Cure& Cure::operator=(const Cure& cure)
{
	std::cout << "Cure assignation operator" << std::endl;
	if (this != &cure)
	{
		AMateria::operator=(cure);
		mType = cure.GetType();
	}
	return (*this);
}

Cure::~Cure()
{
	std::cout << "Cure destructor" << std::endl;
}

AMateria* Cure::Clone() const
{
	AMateria* clonedCure = new Cure(*this);

	std::cout << "Cure Materia cloned. Returning a new Cure Materia" << std::endl;

	return (clonedCure);
}

void Cure::Use(ICharacter& target)
{
    std::cout << "* heals ";
	std::cout << target.GetName() << "’s wounds *" << std::endl;
}