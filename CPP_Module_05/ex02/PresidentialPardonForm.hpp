#include "AForm.hpp"

#define PRESIDENT_REQUIRED_SIGN_GRADE (25)
#define PRESIDENT_REQUIRED_EXEC_GRADE (5)

class PresidentialPardonForm : public AForm 
{
	public:
		PresidentialPardonForm();
		PresidentialPardonForm(const std::string& targetName);
		PresidentialPardonForm(const PresidentialPardonForm& other);
		PresidentialPardonForm& operator=(const PresidentialPardonForm& other);
		void AnnouncePresidentialPardon() const;
		virtual ~PresidentialPardonForm();
		virtual void Execute(Bureaucrat const & executor) const;
	private:
}; 