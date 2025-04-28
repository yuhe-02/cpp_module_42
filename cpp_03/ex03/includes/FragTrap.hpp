#ifndef __FRAGTRAP_HPP__
#define __FRAGTRAP_HPP__

#include "./ClapTrap.hpp"
#include <string>

#define DF3_HP 100
#define DF3_EP 100
#define DF3_AD 30

class FragTrap : public virtual ClapTrap
{
  public:
    FragTrap();
    FragTrap(const std::string name);
    FragTrap(const FragTrap &other);
    ~FragTrap();
    FragTrap &operator=(const FragTrap &other);
    void highFivesGuys(void);
};
#endif