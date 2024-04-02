#ifndef ICE_HPP
#define ICE_HPP

#include "AMateria.hpp"

class Ice : public AMateria
{
	private:
		//AMateria 에서 상속받은 std::string type
	public:
		Ice();
		Ice(const Ice &other);
		virtual ~Ice();

		Ice &operator=(const Ice &other);

		//상속받은 std::string const &getType() const;
		virtual AMateria *clone() const;
		virtual void use(ICharacter &target);
};

#endif