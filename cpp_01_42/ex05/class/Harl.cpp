#include "Harl.hpp"
#include <iostream>

const char	*signals[] = {
	"DEBUG",
	"INFO",
	"WARNING",
	"ERROR"
};

Harl::Harl() {
    m_fpFunc[0] = &Harl::debug;
    m_fpFunc[1] = &Harl::info;
    m_fpFunc[2] = &Harl::warning;
    m_fpFunc[3] = &Harl::error;
}

Harl::~Harl() {}

void Harl::debug( void ) {
	std::cout << "I love having extra bacon for my "
		"7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl;
}

void Harl::info( void ) {
	std::cout << "I cannot believe adding extra bacon costs more money. You didn\'t put "
		"enough bacon in my burger! If you did, I wouldn\'t be asking for more!" << std::endl;
}

void Harl::warning( void ) {
	std::cout << "I think I deserve to have some extra bacon for free. I\'ve been coming for "
		"years whereas you started working here since last month." << std::endl;
}

void Harl::error( void ) {
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

void Harl::complain(std::string level) {
	for (int i = 0; i < 4; i++) {
		if (level.compare(signals[i]) == 0) {
			std::cout << "["<< signals[i] << "]" << std::endl;
			(this->*m_fpFunc[i])();
		}
	}
}