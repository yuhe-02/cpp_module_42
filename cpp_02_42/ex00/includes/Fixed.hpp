#ifndef __FIXED_HPP__
# define __FIXED_HPP__

#include <string>
class Fixed {
	private:
		int fixedPointValue;                  
    	static const int fractionalBits = 8;  
	public:
		Fixed();
		~Fixed();
		Fixed(const Fixed& other);
		Fixed& operator=(const Fixed& other);
		int getRawBits( void ) const;
		void setRawBits( int const raw );
};
#endif