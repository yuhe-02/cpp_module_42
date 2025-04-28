#include "../includes/Zombie.hpp"

Zombie::Zombie() : m_name("") {}
Zombie::Zombie(std::string name) : m_name(name) {}

Zombie::~Zombie()
{
    std::cout << this->m_name << ": has been dealt with." << std::endl;
}

void Zombie::announce(void) const
{
    std::cout << this->m_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::setName(std::string name)
{
    this->m_name = name;
}