#include "AForm.hpp"

#define SHRUBBERY_REQUIRED_SIGN_GRADE (145)
#define SHRUBBERY_REQUIRED_EXEC_GRADE (137)

#include <fstream>

class ShrubberyCreationForm : public AForm 
{
	public:
		ShrubberyCreationForm();
		ShrubberyCreationForm(const std::string& targetName);
		ShrubberyCreationForm(const ShrubberyCreationForm& other);
		ShrubberyCreationForm& operator=(const ShrubberyCreationForm& other);
		virtual ~ShrubberyCreationForm();
		void WriteASCIITreesToFile() const;
		virtual void Execute(Bureaucrat const & executor) const;
	private:
};