#include "PhoneBook.hpp"

namespace print
{
	void	PrintInformation(void)
	{
		std::cout << "+-----------------------------------------+" << std::endl;
		std::cout << "|     Enter ADD to save a new contact     |" << std::endl;
		std::cout << "|   Enter SEARCH to search for a contact  |" << std::endl;
		std::cout << "|   Enter EXIT or EOF to quit the program |" << std::endl;
		std::cout << "+-----------------------------------------+" << std::endl;
	}
	
	void	PrintErrorMessage(const char *erroMessage)
	{
		std::cerr << erroMessage << std::endl;
	}
}

int main()
{
	PhoneBook phoneBook;
	Contact contact;
	std::string input;

	while(true)
	{
		print::PrintInformation();
		std::getline(std::cin, input);
		if (std::cin.eof() == true)
		{
			return (ERROR_CODE);
		}
		if (input == "ADD")
		{
			phoneBook.Add();
		}
		else if (input == "SEARCH")
		{
			phoneBook.Search();
		}
		else if (input == "EXIT")
		{
			phoneBook.Exit(0);
		}
		else
		{
			print::PrintErrorMessage("INVALID INPUT. Please try again");
		}
	}
	return (0);
}