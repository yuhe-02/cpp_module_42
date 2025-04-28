#include "../includes/Zombie.hpp"

Zombie::Zombie(std::string name) { this->m_name = name; }

Zombie::~Zombie() {
  std::cout << this->m_name << ": has been dealt with." << std::endl;
}

void Zombie::announce(void) {
  std::cout << this->m_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}