#ifndef INTERN_HPP
#define INTERN_HPP

#define TOTAL_FORM_COUNT (3)
#define PFORM ("Presidential")
#define RFORM ("Robotomy")
#define SFORM ("Shrubbery")

#include <iostream>
#include "AForm.hpp"

class Intern
{
    public: 
        Intern();
        Intern(const Intern& other);
        Intern& operator=(const Intern& other);
        ~Intern();
        AForm* CreatePresidentialPardonForm(const std::string& target);
        AForm* CreateRobotomyRequestForm(const std::string& target);
        AForm* CreateShrubberyCreationForm(const std::string& target);
        AForm* MakeForm(const std::string& name, const std::string& target);
		int FindForm(const std::string& name);
    class FormNotFoundException : public std::exception
    {
        public:
            virtual const char* what() const throw();
    };

    private:
        static const std::string formNames[TOTAL_FORM_COUNT];
		static AForm* (Intern::*formDatabase[TOTAL_FORM_COUNT])(const std::string &);
};

#endif