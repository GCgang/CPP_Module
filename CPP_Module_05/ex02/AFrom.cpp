#include "AForm.hpp"

AForm::AForm()
	: mName("Empty Form")
	, mbSigned(false)
	, mSignGrade(150)
	, mExecuteGrade(150)
{
}

AForm::AForm(const std::string& name, int signGrade, int executeGrade)
    : mName(name)
	, mbSigned(false)
	, mSignGrade(signGrade)
	, mExecuteGrade(executeGrade)
{
    if(mSignGrade < HIGHEST_GRADE || mExecuteGrade < HIGHEST_GRADE)
	{
        throw GradeTooHighException();
    } 
    if(mSignGrade > LOWEST_GRADE || mExecuteGrade > LOWEST_GRADE)
	{
        throw GradeTooLowException();
    }
}

AForm::AForm(const AForm& other)
	: mName(other.GetName())
	, mbSigned(other.GetSigned())
	, mSignGrade(other.GetSignGrade())
	, mExecuteGrade(other.GetExecuteGrade())
{
	if(mSignGrade < HIGHEST_GRADE || mExecuteGrade < HIGHEST_GRADE)
	{
        throw GradeTooHighException();
    } 
    if(mSignGrade > LOWEST_GRADE || mExecuteGrade > LOWEST_GRADE)
	{
        throw GradeTooLowException();
    }
}

AForm& AForm::operator=(const AForm& other)
{
	static_cast<void>(other);
	throw std::runtime_error("Copy assignment is not allowed");
}

AForm::~AForm()
{
}

std::string AForm::GetName() const
{
	return (mName);
}

bool AForm::GetSigned() const
{
	return (mbSigned);
}

int AForm::GetSignGrade() const
{
	return (mSignGrade);
}

int AForm::GetExecuteGrade() const
{
	return (mExecuteGrade);
}

void AForm::BeSigned(const Bureaucrat& bureaucrat)
{
    if(bureaucrat.GetGrade() > mSignGrade) 
	{
        throw GradeTooLowException();
    }
    mbSigned = true;
}

void AForm::IsExcutable(Bureaucrat const & executor) const
{
	if (GetSigned() == false)
	{
		throw AForm::FormNotSignedException();
	}
	if (GetExecuteGrade() < executor.GetGrade())
	{
		throw AForm::GradeTooHighException();
	}
}

const char* AForm::GradeTooHighException::what() const throw()
{
    return ("Form Grade too high!");
}

const char* AForm::GradeTooLowException::what() const throw()
{
	return ("Form Grade too low!");
}

const char* AForm::FormNotSignedException::what() const throw()
{
	return ("Error: The form has not been signed");
}

const char* AForm::FileErrorException::what() const throw()

{
	return ("Error: An error occurred with the file operation");
}

std::ostream& operator<<(std::ostream& os, const AForm& form)
{
    os << "Form name: ";
	os << form.GetName();
	os << ", is signed: ";
	os << (form.GetSigned() == true ? "Yes" : "No");
	os << ", sign grade required: ";
	os << form.GetSignGrade();
	os << ", execute grade required: ";
	os << form.GetExecuteGrade();
    return (os);
}