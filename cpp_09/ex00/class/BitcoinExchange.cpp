#include "../includes/BitcoinExchange.hpp"
#include <iostream>

BitcoinExchange::BitcoinExchange() {
	std::cout << "BitcoinExchange " << "default constructor called" << std::endl;
}

BitcoinExchange::~BitcoinExchange() {
	std::cout << "BitcoinExchange " << "default destructor called" << std::endl;
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &copy) {
	(void)copy;
	std::cout << "BitcoinExchange " << "copy constructor called" << std::endl;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &copy) {
	(void)copy;
	std::cout << "BitcoinExchange " << "copy assignment called" << std::endl;
	if (this == &copy)
		return *this;
	return *this;
}
