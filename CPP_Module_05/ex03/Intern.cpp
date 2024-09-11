#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

const std::string Intern::formNames[TOTAL_FORM_COUNT] =
{
    PFORM,
    RFORM,
    SFORM
};

AForm* (Intern::*Intern::formDatabase[TOTAL_FORM_COUNT])(const std::string &) =
{
    &Intern::CreatePresidentialPardonForm,
    &Intern::CreateRobotomyRequestForm,
    &Intern::CreateShrubberyCreationForm
};

Intern::Intern()
{
}

Intern::Intern(const Intern& other)
{
	static_cast<void>(other);
}

Intern& Intern::operator=(const Intern& other)
{
	static_cast<void>(other);
	return (*this);
}

Intern::~Intern()
{
}

AForm* Intern::CreatePresidentialPardonForm(const std::string& target)
{
    AForm* PresidentForm;

    PresidentForm = new PresidentialPardonForm(target);
	std::cout << "Intern creates " << PFORM << std::endl;
    return (PresidentForm);
}

AForm* Intern::CreateRobotomyRequestForm(const std::string& target)
{
    AForm* RobotomyForm;

    RobotomyForm = new RobotomyRequestForm(target);
	std::cout << "Intern creates " << RFORM << std::endl;
    return (RobotomyForm);
}

AForm* Intern::CreateShrubberyCreationForm(const std::string& target)
{
    AForm* ShrubberyForm;

    ShrubberyForm = new ShrubberyCreationForm(target);
	std::cout << "Intern creates " << SFORM << std::endl;
    return (ShrubberyForm);
}

int Intern::FindForm(const std::string& name)
{
    for (int i = 0; i < TOTAL_FORM_COUNT; i++)
    {
        if (Intern::formNames[i] == name)
        {
			return (i);
        }
    }
	throw Intern::FormNotFoundException();
}

AForm* Intern::MakeForm(const std::string& name, const std::string& target)
{
	try
	{
		int formIndex = FindForm(name);
		return ((this->*formDatabase[formIndex])(target));
	}
	catch (std::exception& e)
	{
		std::cerr << e.what() << std::endl;
		return (NULL);
	}
}

const char* Intern::FormNotFoundException::what() const throw()
{
    return ("Error: The form name you entered does not exist.");
}
