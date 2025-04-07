#include "ScalarConverter.hpp"
#include <iostream>
#include <sstream>

ScalarConverter::ScalarConverter() {
	std::cout << "ScalarConverter " << "default constructor called" << std::endl;
}

ScalarConverter::~ScalarConverter() {
	std::cout << "ScalarConverter " << "default destructor called" << std::endl;
}

ScalarConverter::ScalarConverter(const ScalarConverter &copy) {
	std::cout << "ScalarConverter " << "copy constructor called" << std::endl;
	(void)copy;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &copy) {
	std::cout << "ScalarConverter " << "copy assignment called" << std::endl;
	(void)copy;
	return *this;
}

bool isSpecial(const std::string &str)
{
	return (str == "nan" || str == "-inf" || str == "+inf" || str == "-nan");
}

bool isPrintable(int c) {
	return (c >= 32 && c <= 126);
}

bool isChar(const std::string &str) {
	if (str.length() == 1) {
		return true;
	}
	return false;
}

bool isInt(const std::string &str) {
	if (str.length() == 0) {
		return false;
	}
	for (size_t i = 0; i < str.length(); ++i) {
		if (!isdigit(str[i])) {
			return false;
		}
	}
	return true;
}

bool isFloat(const std::string &str) {
	if (str.length() == 0) {
		return false;
	}
	for (size_t i = 0; i < str.length(); ++i) {
		if (!isdigit(str[i]) && str[i] != '.' && str[i] != 'f') {
			return false;
		}
	}
	return true;
}

bool isDouble(const std::string &str) {
	if (str.length() == 0) {
		return false;
	}
	for (size_t i = 0; i < str.length(); ++i) {
		if (!isdigit(str[i]) && str[i] != '.') {
			return false;
		}
	}
	return true;
}
void ScalarConverter::convertChar(const std::string &str) {
	int number_part;
	std::string rest_part;
	std::cout << "char: ";
	if (isSpecial(str)) {
		throw ImpossibleException();
	}
	std::stringstream ss(str);
	ss >> number_part;
	ss >> rest_part;
	if (!isPrintable(number_part)) {
		throw NonPrintableException();
	}
	std::cout << "'" << static_cast<char>(number_part) << "'" << std::endl;
	return;
}

void ScalarConverter::convert(const std::string &str) {
	std::cout << "ScalarConverter " << "convert function called" << std::endl;
	try {
		ScalarConverter::convertChar(str);
	} catch (const std::exception & e) {
		std::cerr << e.what() << std::endl;
	}
	// covertInt(str);
	// covertFloat(str);
	// covertDouble(str);
	// TODO add logic
	// Conversion logic goes here
}

const char *ScalarConverter::NonPrintableException::what() const throw() {
	return ("Non displayable");
}

const char *ScalarConverter::ImpossibleException::what() const throw() {
	return ("impossible");
}
