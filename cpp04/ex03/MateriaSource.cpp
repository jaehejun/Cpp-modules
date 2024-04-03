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
		materia[i] = NULL;
		if (other.materia[i])
		{
			materia[i] = other.materia[i]->clone();
		}
	}
}

MateriaSource::~MateriaSource()
{
	std::cout << "MateriaSource destructor called" << std::endl;
	for (int i = 0; i < 4; i++)
	{
		delete materia[i];
		materia[i] = NULL;
	}
}

MateriaSource &MateriaSource::operator=(const MateriaSource &other)
{
	std::cout << "MateriaSource assignment operator called" << std::endl;
	if (this != &other)
	{
		for (int i = 0; i < 4; i++)
		{
			delete materia[i];
			materia[i] = NULL;
			if (other.materia[i] != NULL)
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
			std::cout << "Learn [" << m->getType() << "] Materia!" << std::endl;
			materia[i] = m;
			break;
		}
		if (i == 3)
		{
			std::cout << "Can't know more than 4 Materias!" << std::endl;
			delete m;
		}
	}
}

AMateria *MateriaSource::createMateria(std::string const &type)
{
	for (int i = 0; i < 4; i++)
	{
		if (materia[i] && materia[i]->getType() == type)
		{
			std::cout << "Create [" << materia[i]->getType() << "] Materia!" << std::endl;
			return materia[i]->clone();
		}
	}
	std::cout << "Unkown Type!" << std::endl;
	return 0;
}