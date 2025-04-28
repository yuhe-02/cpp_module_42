#ifndef __DOG_HPP__
#define __DOG_HPP__

#include "./Animal.hpp"
#include <string>

class Dog : public Animal
{
  private:
    Brain *brain;

  public:
    Dog();
    ~Dog();
    Dog(const Dog &other);
    Dog &operator=(const Dog &other);
    void makeSound() const;
    void showBrain(void) const;
    void randomSet(void);
};

#endif