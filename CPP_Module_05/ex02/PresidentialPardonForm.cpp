#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm()
	: AForm()
{
}

PresidentialPardonForm::PresidentialPardonForm(const std::string& targetName)
	: AForm(targetName, PRESIDENT_REQUIRED_SIGN_GRADE, PRESIDENT_REQUIRED_EXEC_GRADE)
{
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other)
	: AForm(other)
{
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other)
{
	if (this != &other)
	{
		AForm::operator=(other);
	}
	return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm()
{
}

void PresidentialPardonForm::AnnouncePresidentialPardon() const
{
	std::cout << GetName();
	std::cout << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}

void PresidentialPardonForm::Execute(Bureaucrat const & executor) const
{
	IsExcutable(executor);
	AnnouncePresidentialPardon();
}