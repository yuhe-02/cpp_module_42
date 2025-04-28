#ifndef __WRONGDOG_HPP__
#define __WRONGDOG_HPP__

#include "./WrongAnimal.hpp"
#include <string>

class WrongDog : public WrongAnimal
{
  public:
    WrongDog();
    ~WrongDog();
    WrongDog(const WrongDog &other);
    WrongDog &operator=(const WrongDog &other);
    void makeSound() const;
};

#endif