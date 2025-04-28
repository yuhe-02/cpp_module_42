#include "B.hpp"
#include <iostream>

B::~B()
{
    std::cout << "B "
              << "default destructor called" << std::endl;
}
