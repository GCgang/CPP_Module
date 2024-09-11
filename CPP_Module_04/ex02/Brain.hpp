#pragma once
#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>
#include <fstream>
#include <cstdlib>

class Brain
{
	public:
		Brain();
		Brain(const Brain& brain);
		Brain& operator=(const Brain& brain);
		~Brain();
		void InitializeIdeas() const;
		void PrintIdeas() const;
	private:
		std::string* mIdeas;
		static const int IDEA_COUNT = 100;
};

#endif 
