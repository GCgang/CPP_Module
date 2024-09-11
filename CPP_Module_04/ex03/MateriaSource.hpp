#pragma once
#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
	public:
		MateriaSource();
		MateriaSource(const MateriaSource& materiaSource);
		MateriaSource& operator=(const MateriaSource& materiaSource);
		virtual ~MateriaSource();
		virtual void LearnMateria(AMateria* materia);
		virtual AMateria* CreateMateria(std::string const& type);
	private:
		static const int MAX_SLOT = 4;
		AMateria* mInventory[MAX_SLOT];
};

#endif // MATERIASOURCE_HPP 