#ifndef ICE_HPP
#define ICE_HPP

#include "AMateria.hpp"

class Ice : public AMateria
{
	private:
		std::string type;
	
	public:
		Ice();
		Ice(const std::string &type);
		Ice(const Ice &other);
		~Ice();

		Ice &operator=(const Ice &other);

		virtual Ice *clone() const;
};

#endif