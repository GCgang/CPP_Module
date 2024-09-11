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
		void	Complain(std::string level);
		void	SetLogFunctions(void);
	private:
		void	debug(void);
		void	info(void);
		void	warning(void);
		void	error(void);
		std::string mlogLevel[LEVEL_COUNT];
		void 	(Harl::*mlogFunctions[LEVEL_COUNT])();
};

#endif // HARL_HPP