#include "Harl.hpp"

Harl::Harl()
{
}

Harl::~Harl()
{
}

void	Harl::Complain(std::string level)
{
	std::string logLevel[LEVEL_COUNT] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	int index = 0;

	while (index < LEVEL_COUNT)
	{
		if (logLevel[index] == level)
			break ;
		index++;
	}
	if (index < LEVEL_COUNT)
	{
		while (index < LEVEL_COUNT)
		{
			(this->*(mlogFunctions[index]))();
			index++;
		}
	}
	else
	{
		std::cerr << "Invalid log level provided" << std::endl;
	}
}

void	Harl::debug(void)
{
	std::cout << "[DEBUG]" << std::endl;
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger." << std::endl;
	std::cout << "I really do!" << std::endl;
	std::cout << std::endl;
}

void	Harl::info(void)
{
	std::cout << "[INFO]" << std::endl;
	std::cout << "I canot believe adding extra bacon costs more money." << std::endl;
	std::cout << "You didn't put enough bacon in my burger! If you did, I wouldn't be asking for more!" << std::endl;
	std::cout << std::endl;
}

void	Harl::warning(void)
{
	std::cout << "[WARNING]" << std::endl;
	std::cout << "I think I deserve to have some extra bacon for free." << std::endl;
	std::cout << "I've been coming for years whereas you started working here since last month." << std::endl;
	std::cout << std::endl;
}

void	Harl::error(void)
{
	std::cout << "[ERROR]" << std::endl;
	std::cout << "This is unacceptable! I want to seak to the manager now." << std::endl;
	std::cout << std::endl;
}

void	Harl::SetLogFunctions(void)
{
	mlogFunctions[DEBUG] = &Harl::debug;
	mlogFunctions[INFO] = &Harl::info;
	mlogFunctions[WARNING] = &Harl::warning;
	mlogFunctions[ERROR] = &Harl::error;
}
