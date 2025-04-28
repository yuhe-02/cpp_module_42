#ifndef __SCAVTRAP_HPP__
#define __SCAVTRAP_HPP__

#include "./ClapTrap.hpp"
#include <string>

#define DF2_HP 100
#define DF2_EP 50
#define DF2_AD 20
#define DF2_GD false

class ScavTrap : public ClapTrap {
protected:
  bool is_gurdian_;

public:
  ScavTrap();
  ScavTrap(const std::string name);
  ScavTrap(const ScavTrap &other);
  ~ScavTrap();
  ScavTrap &operator=(const ScavTrap &other);
  void attack(const std::string &target = "unknown target");
  void guardGate();
};
#endif