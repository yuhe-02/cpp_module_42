#include "../includes/Fixed.hpp"
#include <iostream>

Fixed::Fixed() : fixedPointValue(0) {
    std::cout << "Default constructor called" << std::endl;
}
Fixed::Fixed(const Fixed& other) {
    std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

Fixed::~Fixed() {
    std::cout << "Destructor called" << std::endl;
}

Fixed& Fixed::operator=(const Fixed& other) {
    std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
		this->fixedPointValue = other.getRawBits();
    return (*this);
}

int  Fixed::getRawBits( void ) const {
	std::cout << "getRawBits member function called" << std::endl;
    return (fixedPointValue);
}

void Fixed::setRawBits( int const raw ) {
	std::cout << "setRawBits member function called" << std::endl;
	this->fixedPointValue = raw;
}
