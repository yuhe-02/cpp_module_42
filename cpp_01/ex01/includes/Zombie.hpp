#ifndef __ZOMBIE_HPP__
#define __ZOMBIE_HPP__

#include <iostream>
#include <string>

class Zombie
{
  private:
    std::string m_name;

  public:
    Zombie();
    Zombie(std::string name);
    ~Zombie();
    void announce(void) const;
    void setName(std::string name);
};

Zombie *zombieHorde(int N, std::string name);

#endif