#ifndef CURE_HPP
#define CURE_HPP

#include "AMateria.hpp"

class Cure : public AMateria
{
	private:
		std::string type;

	public:
		Cure();
		Cure(const std::string &type);
		Cure(const Cure &other);
		~Cure();

		Cure &operator=(const Cure &other);
};

#endif