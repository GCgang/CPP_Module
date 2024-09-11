#pragma once
#ifndef IMATERIASOURCE_HPP
#define IMATERIASOURCE_HPP

#include "AMateria.hpp"

class IMateriaSource
{
	public:
		virtual ~IMateriaSource() {}
		virtual void LearnMateria(AMateria*) = 0;
		virtual AMateria* CreateMateria(std::string const & type) = 0;
};

#endif // IMATERIASOURCE_HPP