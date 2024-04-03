#ifndef AMATERIA_HPP
# define AMATERIA_HPP

#include <string>
#include <iostream>
#include "ICharacter.hpp"

class AMateria
{
	protected:
		std::string type;
		AMateria();
		bool isEquiped;

	public:
		AMateria(std::string const &type);
		AMateria(const AMateria &other);
		virtual ~AMateria();

		AMateria &operator=(const AMateria &other);

		std::string const &getType() const;
		
		virtual AMateria *clone() const = 0;
		virtual void use(ICharacter &target);
		bool getStatus() const;
		void setStatus();
};

#endif