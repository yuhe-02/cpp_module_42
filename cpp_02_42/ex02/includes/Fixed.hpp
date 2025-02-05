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
		bool				operator==(const Fixed& other) const;
		bool				operator!=(const Fixed& other) const;
		bool				operator>=(const Fixed& other) const;
		bool				operator<=(const Fixed& other) const;
		bool				operator>(const Fixed& other) const;
		bool				operator<(const Fixed& other) const;
		Fixed&				operator=(const Fixed& other);
		Fixed 				operator*(const Fixed& other);
		Fixed 				operator+(const Fixed& other);
		Fixed 				operator-(const Fixed& other);
		Fixed 				operator/(const Fixed& other);
		Fixed				operator++( void );
		Fixed				operator++(const int increment);
		Fixed				operator--( void );
		Fixed				operator--(const int decrement);
		int					getRawBits( void ) const;
		void				setRawBits( int const raw );
		int					toInt(void) const;
		float				toFloat(void) const;
		static const Fixed	&max(const Fixed &left, const Fixed &right);
		static const Fixed	&min(const Fixed &left, const Fixed &right);
		static		Fixed	&max(Fixed &left, Fixed &right);
		static		Fixed	&min(Fixed &left, Fixed &right);
};
std::ostream& operator<<(std::ostream& os, const Fixed& fixed);
#endif