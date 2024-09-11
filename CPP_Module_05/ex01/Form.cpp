#include "Form.hpp"

Form::Form()
	: mName("Empty Form")
	, mbSigned(false)
	, mSignGrade(150)
	, mExecuteGrade(150)
{
}

Form::Form(const std::string& name, int signGrade, int executeGrade)
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

Form::Form(const Form& other)
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

Form& Form::operator=(const Form& other)
{
	static_cast<void>(other);
	throw std::runtime_error("Copy assignment is not allowed");
}

Form::~Form()
{
}

std::string Form::GetName() const
{
	return (mName);
}

bool Form::GetSigned() const
{
	return (mbSigned);
}

int Form::GetSignGrade() const
{
	return (mSignGrade);
}

int Form::GetExecuteGrade() const
{
	return (mExecuteGrade);
}

void Form::BeSigned(const Bureaucrat& bureaucrat)
{
    if(bureaucrat.GetGrade() > mSignGrade) 
	{
        throw GradeTooLowException();
    }
    mbSigned = true;
}

const char* Form::GradeTooHighException::what() const throw()
{
    return ("Form Grade too high!");
}

const char* Form::GradeTooLowException::what() const throw()
{
	return ("Form Grade too low!");
}

std::ostream& operator<<(std::ostream& os, const Form& form)
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