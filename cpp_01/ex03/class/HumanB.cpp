#include "HumanB.hpp"
#include <iostream>

HumanB::HumanB(std::string name) : name(name), weapon(NULL) {}
HumanB::~HumanB() {}

void HumanB::setWeapon(Weapon &weapon)
{
    this->weapon = &weapon;
}

void HumanB::attack()
{
    std::cout << this->name;
    if (!this->weapon)
    {
        std::cout << " doesn't have weapon" << std::endl;
    }
    else
    {
        std::cout << " attacks with their " << this->weapon->getType() << std::endl;
    }
}