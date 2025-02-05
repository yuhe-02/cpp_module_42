#ifndef __HARL_HPP__
# define __HARL_HPP__

# include <string>

class Harl {
	private :
		void debug( void );
		void info( void );
		void warning( void );
		void error( void );
		void (Harl::*m_fpFunc[4])( void );
	public :
		Harl();
		~Harl();
		void complain(std::string level);
};
#endif