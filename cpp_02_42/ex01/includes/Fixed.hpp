#ifndef __FIXED_HPP__
# define __FIXED_HPP__

#include <string>
#include <cmath>
class Fixed {
	private:
		int fixedPointValue;                  
    	static const int fractionalBits = 8;  
	public:
		Fixed();
		Fixed(const int num);
		Fixed(const float num);
		~Fixed();
		Fixed(const Fixed& other);
		Fixed&	operator=(const Fixed& other);
		int		getRawBits( void ) const;
		void	setRawBits( int const raw );
		int		toInt(void) const;
		float	toFloat(void) const;
};
std::ostream& operator<<(std::ostream& os, const Fixed& fixed);
#endif