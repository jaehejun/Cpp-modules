#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "ICharater.hpp"

class Character : public ICharacter
{
  private:
    std::string name;
    AMateria *slots[4];
    Character();

  public:
    Character(const std::string &name);
	Character(const Character &other);
    ~Character();

    Character &operator=(const Character &other);

    std::string const &getName() const;
    virtual void equip(AMateria *m);
    virtual void unequip(int idx);
    virtual void use(int idx, ICharacter &target);
};

#endif