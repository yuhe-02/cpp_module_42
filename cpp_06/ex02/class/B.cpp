#include "B.hpp"
#include <iostream>

//TODO delete needless
B::B() {
	std::cout << "B " << "default constructor called" << std::endl;
}

B::~B() {
	std::cout << "B " << "default destructor called" << std::endl;
}

B::B(const B &copy) {
	std::cout << "B " << "copy constructor called" << std::endl;
}

B &B::operator=(const B &copy) {
	std::cout << "B " << "copy assignment called" << std::endl;
	if (this == &copy)
		return *this;
	return *this;
}
