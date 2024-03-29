#ifdef CHARACTER_HPP
#define CHARACTER_HPP

#include "ICharater.hpp"
#include "AMateria.hpp"

class Character : public ICharacter
{
	private:
		std::string name;
		AMateria slot[4];
	
	public:
		Character();
		Character(const std::string &name)
		Character(const Character &other);
		~Character();

		Character &operator=(const Character &other);

		std::string const &getName() const;
		virtual void equip(AMateria *m);
		virtual void unequip(int idx);
		virtual void use(int idx, ICharacter &target);
};

#endif