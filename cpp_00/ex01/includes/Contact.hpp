#ifndef __CONTACT_HPP__
# define __CONTACT_HPP__

# include <iostream>
# include <cctype>
# include <string>
# include <unistd.h>
# include <cstdlib>
# include <iomanip>
# include <cstdio>

# define MEMBER_NUM 5
class Contact {
	private :
		std::string m_firstName;
		std::string m_lastName;
		std::string m_nickName;
		std::string	m_phoneNumber;
		std::string	m_darkestSecret;
		bool		m_isRegisterd;
		bool		_registerValue(int msgIndex, std::string &buf);
	public	:
		Contact();
		~Contact();
		void		showInfo();
		void		registerContact();
		std::string	getFirstName();
		std::string	getLastName();
		std::string	getNickName();
		std::string	getPhoneNumber();
		std::string	getDarkestSecret();
		bool		getIsRegistered();
};
#endif