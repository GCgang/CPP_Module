#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm()
	: AForm()
{	
}

RobotomyRequestForm::RobotomyRequestForm(const std::string& targetName)
	: AForm(targetName, ROBOTOMY_REQUIRED_SIGN_GRADE, ROBOTOMY_REQUIRED_EXEC_GRADE)
{
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other)
	: AForm(other)
{
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other)
{
	if (this != &other)
	{
		AForm::operator=(other);
	}
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}

void RobotomyRequestForm::MakeDrillingNoise() const
{
	std::cout << GetName();
	std::cout << " Grrrrrrrrrrrrr" << std::endl;
}

void RobotomyRequestForm::TryRobotomization() const
{
	std::time_t currentTime;

	std::time(&currentTime);
	srand(currentTime);

	int randomValue = rand();

	if ((randomValue % 2) == true)
	{
		std::cout << "Robotomy of ";
		std::cout << GetName();
		std::cout << " succeeded!" << std::endl;
	}
	else if ((randomValue % 2) == false)
	{
		std::cout << "Robotomy of ";
		std::cout << GetName();
		std::cout << " failed!" << std::endl;
	}
}

void RobotomyRequestForm::Execute(Bureaucrat const & executor) const
{
	IsExcutable(executor);
	MakeDrillingNoise();
	TryRobotomization();
}