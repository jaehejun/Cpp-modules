#include "MateriaSource.hpp"
#include "AMateria.hpp"

MateriaSource::MateriaSource()
{
	std::cout << "MateriaSource default constructor called" << std::endl;
	for (int i = 0; i < 4; i++)
	{
		materia[i] = NULL;
	}
}

MateriaSource::MateriaSource(const MateriaSource &other)
{
	std::cout << "MateriaSource copy constructor called" << std::endl;
	for (int i = 0; i < 4; i++)
	{
		if (other.materia[i])
		{
			materia[i] = other.materia[i]->clone();
		}
		materia[i] = NULL;
	}
}

MateriaSource::~MateriaSource()
{
	std::cout << "MateriaSource destructor called" << std::endl;
}

MateriaSource &MateriaSource::operator=(const MateriaSource &other)
{
	std::cout << "MateriaSource assignment operator called" << std::endl;
	if (this != &other)
	{
		for (int i = 0; i < 4; i++)
		{
			if (other.materia[i])
			{
				materia[i] = other.materia[i]->clone();
			}
		}
	}
	return *this;
}

void MateriaSource::learnMateria(AMateria *m)
{
	for (int i = 0; i < 4; i++)
	{
		if (materia[i] == NULL)
		{
			std::cout << "#############MATERIA[" << i << "]" << "is NULL############" << std::endl;
			materia[i] = m->clone();
			break;
		}
		if (i == 3)
		{
			std::cout << "Can't know more than 4 Materias!" << std::endl;
		}
	}
}

AMateria *MateriaSource::createMateria(std::string const &type)
{
	std::cout << "@@@@@@@@@CREATE MATERIA CALLED@@@@@@@@@@@@" << std::endl;
	if (type != "ice" && type != "cure")
	{
		std::cout << "Unknown type!" << std::endl;
		return 0;
	}
	for (int i = 3; i >= 0; i--)
	{
		std::cout << "@@@@@@@@@MATERIA[" << i << "]:" << materia[i] << "@@@@@@@@@@@@" << std::endl;
		if (materia[i] && materia[i]->getType() == type)
		{
			std::cout << "@@@@@@@@@MATERIA[" << i << "]:" << materia[i]->getType() << "@@@@@@@@@@@@" << std::endl;
			return materia[i]->clone();
		}
		if (i == 0)
		{
			std::cout << "There isn't any of " << type << " Materia" << std::endl;
			return 0;
		}
	}
	return 0;
}