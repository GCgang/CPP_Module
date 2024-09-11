#include "Bureaucrat.hpp"
#include "AForm.hpp"

Bureaucrat::Bureaucrat()
	: mName("No Name")
	, mGrade(LOWEST_GRADE)
{
}

Bureaucrat::Bureaucrat(const std::string& name, int grade)
	: mName(name)
	, mGrade(grade)
{
	if (mGrade < HIGHEST_GRADE)
	{
		throw Bureaucrat::GradeTooHighException();
	}
	else if (mGrade > LOWEST_GRADE)
	{
		throw Bureaucrat::GradeTooLowException();
	}
}

Bureaucrat::Bureaucrat(const Bureaucrat& other)
	: mName(other.GetName())
	, mGrade(other.GetGrade())
{
	if (mGrade < HIGHEST_GRADE)
	{
		throw Bureaucrat::GradeTooHighException();
	}
	else if (mGrade > LOWEST_GRADE)
	{
		throw Bureaucrat::GradeTooLowException();
	}
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other)
{
	static_cast<void>(other);
	throw std::runtime_error("Copy assignment is not allowed");
}

Bureaucrat::~Bureaucrat()
{
}

std::string Bureaucrat::GetName() const
{
	return (mName);
}

int Bureaucrat::GetGrade() const
{
	return (mGrade);
}

void Bureaucrat::IncrementGrade()
{
    if (mGrade <= HIGHEST_GRADE)
	{
        throw Bureaucrat::GradeTooHighException();
    }
    mGrade--;
}

void Bureaucrat::DecrementGrade()
{
    if (mGrade >= LOWEST_GRADE)
	{
        throw Bureaucrat::GradeTooLowException();
    }
    mGrade++;
}

void Bureaucrat::IncrementGrade(int amount)
{
    if(amount < 0)
	{
        throw std::invalid_argument("Amount must be positive");
    }
    if((mGrade - amount) <= 0) 
	{
        throw Bureaucrat::GradeTooHighException();
    }
    mGrade -= amount;
}

void Bureaucrat::DecrementGrade(int amount)
{
	if (amount < 0)
	{
		throw std::invalid_argument("Amount must be positive");
	}
	if ((mGrade + amount) > LOWEST_GRADE)
	{
		throw Bureaucrat::GradeTooLowException();
	}
	mGrade += amount;
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
    return "Grade too high!!!";
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
    return "Grade too low!!!!";
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat)
{
	os << bureaucrat.GetName();
	os << ", bureaucrat grade ";
	os << bureaucrat.GetGrade();
    return (os);
}

void Bureaucrat::SignForm(AForm& form)
{
	if (form.GetSigned() == true)
	{
		std::cout << "The form is already signed" << std::endl;
		return ;
	}
    try
	{
        form.BeSigned(*this);
        std::cout << GetName();
		std::cout << " signed ";
		std::cout << form.GetName() << std::endl;
    }
	catch (const std::exception& e)
	{
        std::cout << GetName();
		std::cout << " couldn't sign ";
		std::cout << form.GetName();
		std::cout << " because ";
		std::cout << e.what() << std::endl;
    }
}

void Bureaucrat::ExecuteForm(const AForm& form)
{
	try
	{
        form.Execute(*this);
        std::cout << GetName();
		std::cout << " executed ";
		std::cout << form.GetName() << std::endl;
    }
	catch (std::exception& e)
	{
        std::cout << "Failed to execute form: ";
		std::cout << e.what() << std::endl;
    }
}