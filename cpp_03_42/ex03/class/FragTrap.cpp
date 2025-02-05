#include "../includes/FragTrap.hpp"
#include <iostream>

FragTrap::FragTrap() : ClapTrap() {
	this->hit_points_ = DF3_HP;
    this->energy_points_ = DF3_EP;
    this->attack_damage_ = DF3_AD;
    std::cout << "FragTrap Default constructor called" << std::endl;
}

FragTrap::FragTrap(const std::string name) : ClapTrap(name) {
	this->hit_points_ = DF3_HP;
    this->energy_points_ = DF3_EP;
    this->attack_damage_ = DF3_AD;
    std::cout << "FragTrap Constructor with " << this->name_ << " argument called " << std::endl;
}

FragTrap::~FragTrap() {
	std::cout << "FragTrap " << this->name_ << " Destructor called"  << std::endl;
}

FragTrap::FragTrap(const FragTrap &other) : ClapTrap(other) {
    std::cout << "FragTrap Copy constructor called " << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap &other) {
    if (this != &other) {
        ClapTrap::operator=(other);
    }
    std::cout << "FragTrap Copy assignment operator called" << std::endl;
    return *this;
}

void FragTrap::highFivesGuys(void) {
    std::cout << "FragTrap " << this->name_ << " is asking for a HIGH FIVE!" << std::endl;
}

