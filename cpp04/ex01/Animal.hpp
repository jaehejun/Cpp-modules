#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>
#include <string>

class Animal
{
  protected:
    std::string type;

  public:
    Animal();
    Animal(const std::string &type);
    Animal(const Animal &other);
    virtual ~Animal();

    Animal &operator=(const Animal &other);

    virtual void makeSound() const;
    void setType(const std::string &type);
    std::string getType() const;
};

#endif