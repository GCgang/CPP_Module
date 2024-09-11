#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm()
	: AForm()
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& targetName)
	: AForm(targetName, SHRUBBERY_REQUIRED_SIGN_GRADE, SHRUBBERY_REQUIRED_EXEC_GRADE)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other)
	: AForm(other)
{
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other)
{
	if (this != &other)
	{
		AForm::operator=(other);
	}
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

void ShrubberyCreationForm::WriteASCIITreesToFile() const
{
    std::string filename = GetName() + "_shrubbery";
	std::ofstream ofs(filename.c_str());

    if (ofs.is_open() == false)
	{
        throw AForm::FileErrorException();
    }

	ofs << "      .      " << std::endl; 
	ofs << "   __/ \\__   " << std::endl; 
	ofs << "   \\     /   " << std::endl; 
	ofs << "   /.'o'.\\   " << std::endl; 
	ofs << "    .o.'.    " << std::endl; 
	ofs << "   .'.'o'.   " << std::endl; 
	ofs << "  o'.o.'.o.  " << std::endl; 
	ofs << " .'.o.'.'.o. " << std::endl; 
	ofs << ".o.'.o.'.o.'." << std::endl; 
	ofs << "   [_____]   " << std::endl; 
	ofs << "    \\___/    " << std::endl; 
    ofs.close();
}

void ShrubberyCreationForm::Execute(Bureaucrat const & executor) const
{
	IsExcutable(executor);
	WriteASCIITreesToFile();
}