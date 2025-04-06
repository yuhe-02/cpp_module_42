#include "Template.hpp"
#include <iostream>

Template::Template() {
	std::cout << "Template " << "default constructor called" << std::endl;
}

Template::~Template() {
	std::cout << "Template " << "default destructor called" << std::endl;
}

Template::Template(const Template &copy) {
	std::cout << "Template " << "copy constructor called" << std::endl;
}

Template &Template::operator=(const Template &copy) {
	std::cout << "Template " << "copy assignment called" << std::endl;
	if (this == &copy)
		return *this;
	return *this;
}
