#pragma once

// #include <string>
// #include <iostream>

class BitcoinExchange
{
private:

public:
	BitcoinExchange();
	BitcoinExchange(const BitcoinExchange &copy);
	BitcoinExchange &operator=(const BitcoinExchange & copy);
	~BitcoinExchange();
};

// std::ostream& operator<<(std::ostream& os, const BitcoinExchange& BitcoinExchange);
// std::ostream& operator<<(std::ostream& os, const BitcoinExchange* BitcoinExchange);
