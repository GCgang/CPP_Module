#include "Harl.hpp"

int main(int argc, char **argv)
{
	Harl harl;

	if (argc != 2)
	{
		std::cerr << "Error: Invalid number of arguments!" << std::endl;
		std::cerr << "Please provide the following arguments: [EXCUTABLE FILE NAME] [LOG LEVEL]" << std::endl;
		return (1);
	}
	if (harl.Complain(static_cast<std::string>(argv[1])) == false)
	{
		std::cerr << "[ Probably complaining about insignificant problems ]" << std::endl;
	}
	return (0);
}