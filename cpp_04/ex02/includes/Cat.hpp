#ifndef __CAT_HPP__
#define __CAT_HPP__

#include "./Animal.hpp"
#include <string>

class Cat : public Animal
{
  private:
    Brain *brain;

  public:
    Cat();
    ~Cat();
    Cat(const Cat &other);
    Cat &operator=(const Cat &other);
    void makeSound() const;
    void showBrain(void) const;
    void randomSet(void);
};

#endif