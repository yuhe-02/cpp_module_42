#include "../includes/Point.hpp"

Point::Point() : x_(0), y_(0){}

Point::Point(const float x, const float y) : x_(x), y_(y){}

Point::Point(const Point& other): x_(other.getX()), y_(other.getY()) {}

Point& Point::operator=(const Point&) {
	return (*this);
}

Point::~Point(){}

const Fixed &Point::getX( void ) const{
	return (this->x_);
}

const Fixed &Point::getY( void ) const{
	return (this->y_);
}





