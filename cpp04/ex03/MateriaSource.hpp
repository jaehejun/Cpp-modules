#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include <iostream>
#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
	private:
		AMateria *materia[4];
		static AMateria *created[10];
		static int createStorage;

	public:
		MateriaSource();
		MateriaSource(const MateriaSource &other);
		~MateriaSource();

		MateriaSource &operator=(const MateriaSource &other);

		virtual void learnMateria(AMateria *);
		virtual AMateria *createMateria(std::string const &type);

		static void clearCreated();
};

#endif