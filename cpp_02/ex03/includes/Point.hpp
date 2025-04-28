#ifndef __POINT_HPP__
#define __POINT_HPP__

#include "Fixed.hpp"
class Point {
private:
  const Fixed x_;
  const Fixed y_;

public:
  Point();
  Point(const float x, const float y);
  Point(const Point &other);
  Point &operator=(const Point &);
  ~Point();
  const Fixed &getX(void) const;
  const Fixed &getY(void) const;
};

bool bsp(Point const a, Point const b, Point const c, Point const point);

#endif