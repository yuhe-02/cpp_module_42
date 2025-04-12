#include "A.hpp"
#include <iostream>

A::~A() {
	std::cout << "A " << "default destructor called" << std::endl;
}
