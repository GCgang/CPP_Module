#include "AForm.hpp"

#define ROBOTOMY_REQUIRED_SIGN_GRADE (72)
#define ROBOTOMY_REQUIRED_EXEC_GRADE (45)
#include <cstdlib>
#include <ctime>

class RobotomyRequestForm : public AForm 
{
	public:
		RobotomyRequestForm();
		RobotomyRequestForm(const std::string& targetName);
		RobotomyRequestForm(const RobotomyRequestForm& other);
		RobotomyRequestForm& operator=(const RobotomyRequestForm& other);
		void MakeDrillingNoise() const;
		void TryRobotomization() const;
		virtual ~RobotomyRequestForm();
		virtual void Execute(Bureaucrat const & executor) const;
	private:
};