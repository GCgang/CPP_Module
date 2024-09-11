#include "Harl.hpp"

Harl::Harl()
	: mLogLevel(0)
{
}

Harl::~Harl()
{
}

bool	Harl::Complain(const std::string& level)
{
	mLogLevel = GetLogLevel(level);
	switch (mLogLevel)
	{
		case DEBUG:
			debug();
			// fallthrough
		case INFO:
			info();
			// fallthrough
		case WARNING:
			warning();
			// fallthrough
		case ERROR:
			error();
			break;
		default:
			return (false);
	}
	return (true);
}

int	Harl::GetLogLevel(const std::string& level)
{
	std::string logLevel[LEVEL_COUNT] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	for (int index = 0; index < LEVEL_COUNT; index++)
	{
		if (logLevel[index] == level)
			return (index);
	}
	return (-1);
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
