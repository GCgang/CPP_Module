#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"

class Form
{
	public:
		Form();
		Form(const std::string& name, int signGrade, int excuteGrade);
		Form(const Form& other);
		Form& operator=(const Form& other);
		~Form();
		std::string GetName() const;
		bool GetSigned() const;
		int GetSignGrade() const;
		int GetExecuteGrade() const;
		void BeSigned(const Bureaucrat& bureaucrat);

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

	private:
		const std::string mName;
		bool mbSigned;
		const int mSignGrade;
		const int mExecuteGrade;
};

std::ostream& operator<<(std::ostream& os, const Form& form);

#endif