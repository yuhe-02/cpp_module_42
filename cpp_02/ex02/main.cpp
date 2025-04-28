#include "includes/Fixed.hpp"
#include <iostream>

// int main( void ) {
// 	Fixed a;
// 	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
// 	Fixed const c( Fixed( -5 ) - Fixed( 2 ) );
// 	Fixed const d( Fixed( -5 ) + Fixed( 2 ) );
// 	Fixed const e( Fixed( -5 ) / Fixed( 0 ) );
// 	std::cout << a << std::endl;
// 	std::cout << ++a << std::endl;
// 	std::cout << a << std::endl;
// 	std::cout << a++ << std::endl;
// 	std::cout << a << std::endl;
// 	// std::cout << b << std::endl;
// 	// std::cout << c << std::endl;
// 	// std::cout << d << std::endl;
// 	// std::cout << e << std::endl;
// 	// std::cout << -5.0 / 0.0 << std::endl;
// 	// std::cout << Fixed::max( a, b ) << std::endl;
// 	return (0);
// }

int main(void) {
  Fixed a;
  Fixed const b(Fixed(5.05f) * Fixed(2));
  Fixed const c(2);
  Fixed const d(2.0f);
  std::cout << a << std::endl;
  std::cout << ++a << std::endl;
  std::cout << a << std::endl;
  std::cout << a++ << std::endl;
  std::cout << a << std::endl;

  std::cout << b << std::endl;

  std::cout << Fixed::max(b, a) << std::endl;
  return (0);
}