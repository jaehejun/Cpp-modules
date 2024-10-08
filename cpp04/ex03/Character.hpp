#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "ICharacter.hpp"

class Character : public ICharacter
{
  private:
    std::string name;
    AMateria *slot[4];

    static AMateria *floor[10];
    static int floorStorage;
    
    Character();

  public:
    Character(const std::string &name);
	  Character(const Character &other);
    virtual ~Character();

    Character &operator=(const Character &other);

    virtual std::string const &getName() const;
    virtual void equip(AMateria *m);
    virtual void unequip(int idx);
    virtual void use(int idx, ICharacter &target);

    static void clearFloor();
};

#endif