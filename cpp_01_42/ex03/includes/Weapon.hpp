#ifndef __WEAPON_HPP__
# define __WEAPON_HPP__

# include <string>
class Weapon {
	private :
		std::string	type;
	public :
		Weapon();
		Weapon(std::string type);
		~Weapon();
		const std::string	&getType( void ) const;
		void		setType( std::string type );
};
#endif