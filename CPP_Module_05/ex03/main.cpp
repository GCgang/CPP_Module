#include "Intern.hpp"

// void Leak()
// {
// 	system("leaks Intern");
// }

int main()
{
	// atexit(Leak);

	Intern robertDeNiro;
	Bureaucrat An("An", 30);

	AForm* XForm = robertDeNiro.MakeForm(PFORM, "XForm");
	AForm* PForm = robertDeNiro.MakeForm(PFORM, "PForm");
	AForm* RForm = robertDeNiro.MakeForm(RFORM, "RForm");
	AForm* SForm = robertDeNiro.MakeForm(SFORM, "SForm");
	std::cout << std::endl;

	if (XForm && PForm && RForm && SForm)
	{
		An.SignForm(*XForm);
		An.ExecuteForm(*XForm);
		std::cout << std::endl;

		An.SignForm(*PForm);
		An.ExecuteForm(*PForm);
		std::cout << std::endl;
		
		An.SignForm(*RForm);
		An.ExecuteForm(*RForm);
		std::cout << std::endl;
		
		An.SignForm(*SForm);
		An.ExecuteForm(*SForm);
	}
	delete(XForm);
	delete(PForm);
	delete(RForm);
	delete(SForm);

    return 0;
}
