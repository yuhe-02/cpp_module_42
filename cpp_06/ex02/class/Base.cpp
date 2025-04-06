#include "Base.hpp"
#include <iostream>


//TODO delete needless
Base::Base() {
	std::cout << "Base " << "default constructor called" << std::endl;
}

Base::~Base() {
	std::cout << "Base " << "default destructor called" << std::endl;
}

Base::Base(const Base &copy) {
	std::cout << "Base " << "copy constructor called" << std::endl;
}

Base &Base::operator=(const Base &copy) {
	std::cout << "Base " << "copy assignment called" << std::endl;
	if (this == &copy)
		return *this;
	return *this;
}

// TODO add logic
