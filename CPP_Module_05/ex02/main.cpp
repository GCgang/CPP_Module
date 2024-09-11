#include <iostream>
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

void HighRankOfficer() {
    Bureaucrat highRankingOfficer("HighRank", 1);

    ShrubberyCreationForm shrubberyForm("Garden");
    RobotomyRequestForm robotomyForm("Robot");
    PresidentialPardonForm presidentialForm("Criminal");

    AForm* forms[] = { &shrubberyForm, &robotomyForm, &presidentialForm };

	for (size_t j = 0; j < sizeof(forms)/sizeof(AForm*); ++j)
	{
		highRankingOfficer.SignForm(*forms[j]);
		highRankingOfficer.ExecuteForm(*forms[j]);
		std::cout << std::endl;
	}

}

void MidRankOfficer() {
    Bureaucrat midRankingOfficer("MidRank", 45);

    ShrubberyCreationForm shrubberyForm("Garden");
    RobotomyRequestForm robotomyForm("Robot");
    PresidentialPardonForm presidentialForm("Criminal");

    AForm* forms[] = { &shrubberyForm, &robotomyForm, &presidentialForm };

	for (size_t j = 0; j < sizeof(forms)/sizeof(AForm*); ++j)
	{
		midRankingOfficer.SignForm(*forms[j]);
		midRankingOfficer.ExecuteForm(*forms[j]);
		std::cout << std::endl;
	}
}

void LowRankOfficer() {
    Bureaucrat lowRankingOfficer("LowRank", 150);

    ShrubberyCreationForm shrubberyForm("Garden");
    RobotomyRequestForm robotomyForm("Robot");
    PresidentialPardonForm presidentialForm("Criminal");

    AForm* forms[] = { &shrubberyForm, &robotomyForm, &presidentialForm };

	for (size_t j = 0; j < sizeof(forms)/sizeof(AForm*); ++j)
	{
		lowRankingOfficer.SignForm(*forms[j]);
		lowRankingOfficer.ExecuteForm(*forms[j]);
		std::cout << std::endl;
	}
}

int main() {
	HighRankOfficer();
	MidRankOfficer();
	LowRankOfficer();
    return 0;
}
