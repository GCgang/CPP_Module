#include "Harl.hpp"

int main()
{
	Harl harl;

	harl.SetLogFunctions();
	harl.Complain("DEBUG");
	harl.Complain("INFO");
	harl.Complain("WARNING");
	harl.Complain("ERROR");
	return (0);
}