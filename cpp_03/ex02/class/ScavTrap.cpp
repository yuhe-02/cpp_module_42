#include "../includes/ScavTrap.hpp"
#include <iostream>

ScavTrap::ScavTrap() : ClapTrap() {
  this->hit_points_ = DF2_HP;
  this->energy_points_ = DF2_EP;
  this->attack_damage_ = DF2_AD;
  this->is_gurdian_ = DF2_GD;
  std::cout << "ScavTrap Default constructor called" << std::endl;
}

ScavTrap::ScavTrap(const std::string name) : ClapTrap(name) {
  this->hit_points_ = DF2_HP;
  this->energy_points_ = DF2_EP;
  this->attack_damage_ = DF2_AD;
  this->is_gurdian_ = DF2_GD;
  std::cout << "ScavTrap Constructor with " << this->name_
            << " argument called " << std::endl;
}

ScavTrap::~ScavTrap() {
  std::cout << "ScavTrap " << this->name_ << " Destructor called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &other)
    : ClapTrap(other), is_gurdian_(other.is_gurdian_) {
  std::cout << "ScavTrap Copy constructor called " << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &other) {
  if (this != &other) {
    ClapTrap::operator=(other);
    this->is_gurdian_ = other.is_gurdian_;
  }
  std::cout << "ScavTrap Copy assignment operator called" << std::endl;
  return *this;
}

void ScavTrap::attack(const std::string &target) {
  if (this->energy_points_ <= 0 || this->hit_points_ <= 0) {
    std::cout << "ScavTrap " << this->name_ << " fails to attack." << std::endl;
    return;
  }
  std::cout << "ScavTrap " << this->name_ << " attacks " << target
            << ", causing " << this->attack_damage_ << " points of damage!"
            << std::endl;
  this->energy_points_--;
  return;
}

void ScavTrap::guardGate() {
  this->is_gurdian_ = true;
  std::cout << "ScavTrap " << this->name_ << " becomes guardian." << std::endl;
}
