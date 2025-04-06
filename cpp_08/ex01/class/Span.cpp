#include "Span.hpp"
#include <iostream>

Span::Span() {
	std::cout << "Span " << "default constructor called" << std::endl;
}

Span::~Span() {
	std::cout << "Span " << "default destructor called" << std::endl;
}

Span::Span(const Span &copy) {
	std::cout << "Span " << "copy constructor called" << std::endl;
}

Span &Span::operator=(const Span &copy) {
	std::cout << "Span " << "copy assignment called" << std::endl;
	if (this == &copy)
		return *this;
	return *this;
}
