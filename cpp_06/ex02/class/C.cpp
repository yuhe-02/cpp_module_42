#include "C.hpp"
#include <iostream>

//TODO delete needless
C::C() {
	std::cout << "C " << "default constructor called" << std::endl;
}

C::~C() {
	std::cout << "C " << "default destructor called" << std::endl;
}

C::C(const C &copy) {
	std::cout << "C " << "copy constructor called" << std::endl;
}

C &C::operator=(const C &copy) {
	std::cout << "C " << "copy assignment called" << std::endl;
	if (this == &copy)
		return *this;
	return *this;
}
