#ifndef __CLAPTRAP_HPP__
#define __CLAPTRAP_HPP__

#include <climits>
#include <string>

#define DF_HP 10
#define DF_EP 10
#define DF_AD 0
#define DF_NAME "anonymous"
class ClapTrap {
protected:
  std::string name_;
  unsigned int hit_points_;
  unsigned int energy_points_;
  unsigned int attack_damage_;

public:
  ClapTrap();
  virtual ~ClapTrap();
  ClapTrap(const std::string name);
  ClapTrap(const ClapTrap &other);
  ClapTrap &operator=(const ClapTrap &other);
  virtual void attack(const std::string &target = "unknown target");
  void takeDamage(unsigned int amount = 1);
  void beRepaired(unsigned int amount = 1);
};
#endif