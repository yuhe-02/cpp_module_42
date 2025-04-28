#ifndef __DIAMONDTRAP_HPP__
#define __DIAMONDTRAP_HPP__

#include "./FragTrap.hpp"
#include "./ScavTrap.hpp"
#include <string>

class DiamondTrap : public FragTrap, public ScavTrap
{
  public:
    std::string name_;

  public:
    DiamondTrap();
    DiamondTrap(const std::string name);
    DiamondTrap(const DiamondTrap &other);
    ~DiamondTrap();
    DiamondTrap &operator=(const DiamondTrap &other);
    void attack(const std::string &target = "unknown target");
    void whoAmI();
};
#endif