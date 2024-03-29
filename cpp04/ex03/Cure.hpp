#ifndef CURE_HPP
#define CURE_HPP

#include "AMateria.hpp"

class Cure : public AMateria
{
	private:
		//AMateria 에서 상속받은 std::string type
	public:
		Cure();
		Cure(const std::string &type);
		Cure(const Cure &other);
		~Cure();

		Cure &operator=(const Cure &other);

		//상속받은 std::string const &getType() const;
		virtual AMateria *clone() const;
		virtual void use(ICharacter &target);
};

#endif