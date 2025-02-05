#include "../includes/Fixed.hpp"
#include <iostream>
#include <cmath>

Fixed::Fixed() : fixedPointValue(0) {
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int num) {
	std::cout << "Int constructor called" << std::endl;
    this->fixedPointValue = num << Fixed::fractionalBits;
}

// やっていることは、intの時と同じ。Intと違ってシフト演算できないから掛け算で計算している。
Fixed::Fixed(const float num) {
	std::cout << "Float constructor called" << std::endl;
    this->fixedPointValue = roundf(num * (float)(1 << Fixed::fractionalBits));
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
    return *this;
}

int  Fixed::getRawBits( void ) const {
	// std::cout << "getRawBits member function called" << std::endl;
    return (fixedPointValue);
}

void Fixed::setRawBits( int const raw ) {
	// std::cout << "setRawBits member function called" << std::endl;
	this->fixedPointValue = raw;
}

int	Fixed::toInt(void) const {
	return (this->fixedPointValue >> Fixed::fractionalBits);
}

float	Fixed::toFloat(void) const {
	return ((float)this->fixedPointValue / (float)(1 << Fixed::fractionalBits));
}

// TODO understand
std::ostream& operator<<(std::ostream& os, const Fixed& fixed) {
    os << fixed.toFloat();
        return os;
}
