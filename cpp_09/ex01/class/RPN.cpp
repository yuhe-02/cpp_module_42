#include "../includes/RPN.hpp"
#include <iostream>

RPN::RPN() {
	std::cout << "RPN " << "default constructor called" << std::endl;
}

RPN::~RPN() {
	std::cout << "RPN " << "default destructor called" << std::endl;
}

RPN::RPN(const RPN &copy) {
	std::cout << "RPN " << "copy constructor called" << std::endl;
}

RPN &RPN::operator=(const RPN &copy) {
	std::cout << "RPN " << "copy assignment called" << std::endl;
	if (this == &copy)
		return *this;
	return *this;
}
