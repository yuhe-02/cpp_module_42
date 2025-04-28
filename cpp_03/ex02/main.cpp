#include "FragTrap.hpp"
#include <iostream>

int main() {
  std::cout << "Creating fragTrap1..." << std::endl;
  FragTrap fragTrap1("Fraggy");
  std::cout << std::endl;

  std::cout << "Creating fragTrap2 using copy constructor..." << std::endl;
  FragTrap fragTrap2(fragTrap1);
  std::cout << std::endl;

  std::cout << "Creating fragTrap3 using assignment operator..." << std::endl;
  FragTrap fragTrap3("Test");
  fragTrap3 = fragTrap1;
  std::cout << std::endl;

  std::cout << "Calling highFivesGuys on fragTrap1..." << std::endl;
  fragTrap1.highFivesGuys();
  std::cout << std::endl;

  std::cout << "Destroying objects..." << std::endl;
  return 0;
}