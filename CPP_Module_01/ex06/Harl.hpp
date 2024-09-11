#pragma once
#ifndef HARL_HPP
# define HARL_HPP

#include <iostream>
#include <string>

enum eLevel
{
	DEBUG,
	INFO,
	WARNING,
	ERROR,
	LEVEL_COUNT
};

class Harl
{
	public:
		Harl();
		~Harl();
		bool	Complain(const std::string& level);
		int		GetLogLevel(const std::string& level);
	private:
		void	debug(void);
		void	info(void);
		void	warning(void);
		void	error(void);
		int	mLogLevel;
};

#endif // HARL_HPP