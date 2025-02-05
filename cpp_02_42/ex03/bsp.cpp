#include "includes/Point.hpp"
#include <iostream>

// TODO understand external cross
static Point calc_edge_vector(const Point &A, const Point &B) {
	const float diff_x = B.getX().toFloat() - A.getX().toFloat();
	const float diff_y = B.getY().toFloat() - A.getY().toFloat();
	// std::cout << B.getX() << std::endl;
	// std::cout << A.getX() << std::endl;
	Point res(diff_x, diff_y);
	return (res);
}

static Fixed calc_cross(const Point &A, const Point &B, Point const &point) {
	const Point ab = calc_edge_vector(A, B);
	const Point ap = calc_edge_vector(A, point);
	Fixed uxvy = Fixed(ab.getX()) * Fixed(ap.getY());
	Fixed uyvx = Fixed(ab.getY()) * Fixed(ap.getX());
	return (uxvy - uyvx);
}

bool bsp( Point const a, Point const b, Point const c, Point const point) {
	const Fixed cross_a = calc_cross(a, b, point);
	const Fixed cross_b = calc_cross(b, c, point);
	const Fixed cross_c = calc_cross(c, a, point);
    return (cross_a > Fixed(0) && cross_b > Fixed(0) && cross_c > Fixed(0)) ||
           (cross_a < Fixed(0) && cross_b < Fixed(0) && cross_c < Fixed(0));
}
