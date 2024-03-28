#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal
{
  private:
    Brain *brain;

  public:
    Cat();
    Cat(const Cat &other);
    ~Cat();

    Cat &operator=(const Cat &other);

    virtual void makeSound() const;
    void setIdea(const std::string &idea);
    void getIdeas();
};

#endif