#ifndef __CAT_HPP__
#define __CAT_HPP__

#include "./Animal.hpp"
#include <string>

class Cat : public Animal
{
  public:
    Cat();
    ~Cat();
    Cat(const Cat &other);
    Cat &operator=(const Cat &other);
    void makeSound() const;
};

#endif