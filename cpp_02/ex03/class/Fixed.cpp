#include "../includes/Fixed.hpp"
#include <cmath>
#include <iostream>

/**
 * The above C++ code snippet defines constructors for a class named Fixed, with
 * one initializing to 0 and the other taking an integer argument and storing it
 * as a fixed-point value.
 */
Fixed::Fixed() : fixedPointValue(0)
{
    // std::cout << "Default constructor called" << std::endl;
}

/**
 * The Fixed constructor initializes the fixedPointValue using the input integer
 * after left shifting by the fractionalBits amount.
 *
 * @param num The `num` parameter is an integer value that is used to initialize
 * the `Fixed` object.
 */
Fixed::Fixed(const int num)
{
    // std::cout << "Int constructor called" << std::endl;
    this->fixedPointValue = num << Fixed::fractionalBits;
}

/**
 * The above functions are constructors for a class called Fixed in C++, where
 * one initializes a Fixed object with a float value and the other initializes
 * it with another Fixed object.
 *
 * @param num The `num` parameter in the `Fixed` constructor is a floating-point
 * number that is used to initialize the `Fixed` object. It is converted to a
 * fixed-point representation based on the number of fractional bits specified
 * in the `Fixed` class.
 */
Fixed::Fixed(const float num)
{
    // std::cout << "Float constructor called" << std::endl;
    this->fixedPointValue = roundf(num * (float)(1 << Fixed::fractionalBits));
}

/**
 * The above function is the copy constructor for the Fixed class in C++, which
 * initializes a new object with the same value as another object of the same
 * class.
 *
 * @param other In the given code snippet, `other` is a reference to another
 * object of the `Fixed` class that is being passed as an argument to the copy
 * constructor. The copy constructor is used to create a new object as a copy of
 * an existing object. In this case, `other` is the
 */
Fixed::Fixed(const Fixed &other)
{
    // std::cout << "Copy constructor called" << std::endl;
    *this = other;
}

/**
 * The above function is a destructor for a class named Fixed in C++.
 */
Fixed::~Fixed()
{
    // std::cout << "Destructor called" << std::endl;
}

/**
 * The function `getRawBits` returns the value of the `fixedPointValue` member
 * variable.
 *
 * @return The `fixedPointValue` is being returned.
 */
int Fixed::getRawBits(void) const
{
    // std::cout << "getRawBits member function called" << std::endl;
    return (fixedPointValue);
}

/**
 * The function `setRawBits` sets the raw value of a fixed-point number.
 *
 * @param raw The `raw` parameter in the `setRawBits` function is an integer
 * value that represents the raw binary value to be set in the `fixedPointValue`
 * member variable of the `Fixed` class.
 */
void Fixed::setRawBits(int const raw)
{
    // std::cout << "setRawBits member function called" << std::endl;
    this->fixedPointValue = raw;
}

/**
 * The function `toInt` in C++ returns the integer value of a fixed-point number
 * by shifting the fixed point value to the right by the number of fractional
 * bits.
 *
 * @return The `toInt` method is returning the integer value of the fixed-point
 * number after shifting the fixed point value to the right by the number of
 * fractional bits.
 */
int Fixed::toInt(void) const
{
    return (this->fixedPointValue >> Fixed::fractionalBits);
}

/**
 * The function `toFloat` converts a fixed-point value to a floating-point value
 * in C++.
 *
 * @return a floating-point value that represents the fixed-point value stored
 * in the `Fixed` object. It achieves this by dividing the fixed-point value by
 * 2 raised to the power of the number of fractional bits.
 */
float Fixed::toFloat(void) const
{
    return ((float)this->fixedPointValue / (float)(1 << Fixed::fractionalBits));
}

bool Fixed::operator==(const Fixed &other) const
{
    // std::cout << "== operator called" << std::endl;
    return (this->getRawBits() == other.getRawBits());
}

bool Fixed::operator!=(const Fixed &other) const
{
    // std::cout << "!= operator called" << std::endl;
    return (this->getRawBits() != other.getRawBits());
}

bool Fixed::operator>=(const Fixed &other) const
{
    std::cout << ">= operator called" << std::endl;
    return (this->toFloat() >= other.toFloat());
}

bool Fixed::operator>(const Fixed &other) const
{
    // std::cout << "> operator called" << std::endl;
    return (this->getRawBits() > other.getRawBits());
}

bool Fixed::operator<=(const Fixed &other) const
{
    // std::cout << "<= operator called" << std::endl;
    return (this->getRawBits() <= other.getRawBits());
}

bool Fixed::operator<(const Fixed &other) const
{
    // std::cout << "< operator called" << std::endl;
    return (this->getRawBits() < other.getRawBits());
}

/**
 * The function overloads the assignment operator to copy the raw bits from one
 * Fixed object to another.
 *
 * @return The `Fixed` object itself is being returned by the `operator=`
 * function.
 */
Fixed &Fixed::operator=(const Fixed &other)
{
    // std::cout << "= operator called" << std::endl;
    if (this != &other)
        this->fixedPointValue = other.getRawBits();
    return *this;
}
/**
 * The function overloads the multiplication operator (*) for the Fixed class to
 * multiply two Fixed objects and return the result.
 *
 * @param other The `other` parameter in the `operator*` function represents the
 * other `Fixed` object that you want to multiply with the current object.
 *
 * @return The `operator*` function is returning a `Fixed` object which is the
 * result of multiplying the two `Fixed` objects (`this` and `other`) and
 * storing the result in a new `Fixed` object named `result`.
 */

Fixed Fixed::operator*(const Fixed &other)
{
    Fixed result;

    result.setRawBits((this->getRawBits() * other.getRawBits()) >> Fixed::fractionalBits);
    return (result);
}

/**
 * The function overloads the subtraction operator for the Fixed class to
 * subtract two Fixed objects and return the result.
 *
 * @param other The `other` parameter in the `operator-` function represents the
 * Fixed object that is being subtracted from the current Fixed object.
 *
 * @return The `Fixed` object `result` is being returned from the `operator-`
 * function.
 */
Fixed Fixed::operator-(const Fixed &other)
{
    Fixed result;

    result.setRawBits(this->getRawBits() - other.getRawBits());
    return result;
}

/**
 * The function overloads the addition operator for the Fixed class to perform
 * addition on two Fixed objects and return the result.
 *
 * @param other The "other" parameter in the code snippet you provided is a
 * reference to a constant object of the class Fixed. It is used to represent
 * the object that is being added to the current object in the operator+
 * function.
 *
 * @return An object of type `Fixed` is being returned.
 */
Fixed Fixed::operator+(const Fixed &other)
{
    Fixed result;

    result.setRawBits(this->getRawBits() + other.getRawBits());
    return result;
}

/**
 * The function overloads the division operator for the Fixed class to perform
 * division on two Fixed objects.
 *
 * @param other The `other` parameter in the `operator/` function represents the
 * Fixed object that is being divided by the current Fixed object.
 *
 * @return An object of type `Fixed` is being returned from the `operator/`
 * function.
 */
Fixed Fixed::operator/(const Fixed &other)
{
    return (Fixed(this->toFloat() / other.toFloat()));
}

/**
 * The above function overloads the pre-increment operator for a class called
 * Fixed.
 *
 * @return The `Fixed` object itself is being returned after incrementing its
 * value by 1.
 */
Fixed Fixed::operator++(void)
{
    this->setRawBits(this->getRawBits() + 1);
    return (*this);
}

/**
 * The above function overloads the post-increment operator for a class called
 * Fixed.
 *
 * @param incremental The `incremental` parameter in the `Fixed::operator++`
 * function represents the amount by which the `Fixed` object should be
 * incremented. If `incremental` is 0, it will be incremented by 1. Otherwise,
 * it will be incremented by the value of `incremental`.
 *
 * @return An object of type `Fixed` is being returned.
 */
Fixed Fixed::operator++(int)
{
    Fixed before = *this;
    this->setRawBits(this->getRawBits() + 1);
    return (before);
}

/**
 * The above function overloads the decrement operator for a class named Fixed.
 *
 * @return The `Fixed` object itself is being returned after the decrement
 * operation is performed.
 */
Fixed Fixed::operator--(void)
{
    this->setRawBits(this->getRawBits() - 1);
    return (*this);
}

/**
 * The above function overloads the post-decrement operator for a class named
 * Fixed.
 *
 * @param  It looks like you have provided a definition for the post-decrement
 * operator overload function for a class named `Fixed`. This function is used
 * to decrement the value of a `Fixed` object by 1 and return the original value
 * before the decrement operation.
 *
 * @return The post-decrement operator for the Fixed class is being overloaded
 * in this code snippet. The function returns a copy of the Fixed object before
 * the decrement operation is applied.
 */
Fixed Fixed::operator--(int)
{
    Fixed before = *this;
    this->setRawBits(this->getRawBits() - 1);
    return (before);
}

/**
 * The above function overloads the << operator to output the float value of a
 * Fixed object.
 *
 * @return The `std::ostream&` object `os` is being returned after inserting the
 * `fixed.toFloat()` value into it.
 */
std::ostream &operator<<(std::ostream &os, const Fixed &fixed)
{
    os << fixed.toFloat();
    return os;
}

const Fixed &Fixed::max(const Fixed &left, const Fixed &right)
{
    return (left.getRawBits() >= right.getRawBits() ? left : right);
}

const Fixed &Fixed::min(const Fixed &left, const Fixed &right)
{
    return (left.getRawBits() <= right.getRawBits() ? left : right);
}

Fixed &Fixed::max(Fixed &left, Fixed &right)
{
    return (left.getRawBits() >= right.getRawBits() ? left : right);
}

Fixed &Fixed::min(Fixed &left, Fixed &right)
{
    return (left.getRawBits() <= right.getRawBits() ? left : right);
}