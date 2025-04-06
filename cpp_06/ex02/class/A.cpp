#include "A.hpp"
#include <iostream>

//TODO delete needless
A::A() {
	std::cout << "A " << "default constructor called" << std::endl;
}

A::~A() {
	std::cout << "A " << "default destructor called" << std::endl;
}

A::A(const A &copy) {
	std::cout << "A " << "copy constructor called" << std::endl;
}

A &A::operator=(const A &copy) {
	std::cout << "A " << "copy assignment called" << std::endl;
	if (this == &copy)
		return *this;
	return *this;
}
