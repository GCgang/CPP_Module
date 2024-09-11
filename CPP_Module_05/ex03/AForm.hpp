#ifndef AFORM_HPP
#define AFORM_HPP

#include "Bureaucrat.hpp"

class AForm
{
	public:
		AForm();
		AForm(const std::string& name, int signGrade, int excuteGrade);
		AForm(const AForm& other);
		AForm& operator=(const AForm& other);
		virtual ~AForm();
		std::string GetName() const;
		bool GetSigned() const;
		int GetSignGrade() const;
		int GetExecuteGrade() const;
		void BeSigned(const Bureaucrat& bureaucrat);
		void IsExcutable(Bureaucrat const & executor) const;
		virtual void Execute(Bureaucrat const & executor) const = 0;
	class GradeTooHighException : public std::exception
	{
		public:
			virtual const char* what() const throw();
	};

	class GradeTooLowException : public std::exception
	{
		public :
			virtual const char* what() const throw();
	};

	class FormNotSignedException : public std::exception
	{
		public :
			virtual const char* what() const throw();
	};

	class FileErrorException : public std::exception
	{
		public :
			virtual const char* what() const throw();
	};

	private:
		const std::string mName;
		bool mbSigned;
		const int mSignGrade;
		const int mExecuteGrade;
};

std::ostream& operator<<(std::ostream& os, const AForm& form);

#endif