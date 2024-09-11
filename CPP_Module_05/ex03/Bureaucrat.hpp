#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#define HIGHEST_GRADE (1)
#define LOWEST_GRADE (150)

#include <iostream>
class AForm;

class Bureaucrat
{
	public:
		Bureaucrat();
		Bureaucrat(const std::string& name, int grade);
		Bureaucrat(const Bureaucrat& other);
		Bureaucrat& operator=(const Bureaucrat& other);
		~Bureaucrat();
		std::string GetName() const;
		int GetGrade() const;
		void IncrementGrade();
		void DecrementGrade();
		void IncrementGrade(int amount);
		void DecrementGrade(int amount);
		void SignForm(AForm& form);
		void ExecuteForm(const AForm& form);
	class GradeTooHighException : public std::exception
	{
		public:
			virtual const char* what() const throw();
	};

	class GradeTooLowException : public std::exception
	{
		public:
			virtual const char* what() const throw();
	};

	private:
		const std::string mName;
		int mGrade;
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat);

#endif