#include "../includes/DiamondTrap.hpp"
#include <iostream>

DiamondTrap::DiamondTrap() : ClapTrap("anonymous_clap_name")
{
    this->name_ = "anonymous";
    this->hit_points_ = FragTrap::hit_points_;
    this->energy_points_ = ScavTrap::energy_points_;
    this->attack_damage_ = FragTrap::attack_damage_;
    std::cout << "DiamondTrap Default constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(const std::string name) : ClapTrap(name + "_clap_name")
{
    this->name_ = name;
    this->hit_points_ = FragTrap::hit_points_;
    this->energy_points_ = ScavTrap::energy_points_;
    this->attack_damage_ = FragTrap::attack_damage_;
    std::cout << "DiamondTrap Constructor with " << this->name_ << " argument called " << std::endl;
}

DiamondTrap::~DiamondTrap()
{
    std::cout << "DiamondTrap " << this->name_ << " Destructor called" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &other) : ClapTrap(other)
{
    std::cout << "DiamondTrap Copy constructor called " << std::endl;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &other)
{
    if (this != &other)
    {
        ClapTrap::operator=(other);
        this->name_ = other.name_;
        this->hit_points_ = other.hit_points_;
        this->energy_points_ = other.energy_points_;
        this->attack_damage_ = other.attack_damage_;
    }
    std::cout << "DiamondTrap Copy assignment operator called" << std::endl;
    return *this;
}

void DiamondTrap::attack(const std::string &target)
{
    ScavTrap::attack(target);
}

void DiamondTrap::whoAmI()
{
    std::cout << "DiamondTrap name: " << name_ << std::endl;
    std::cout << "base ClapTrap name: " << ClapTrap::name_ << std::endl;
}
