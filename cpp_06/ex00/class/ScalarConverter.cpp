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

void ScalarConverter::convertChar(const std::string &str) {
	int number_part;
	std::string rest_part;
	std::cout << "char: ";
	try {
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
	} 
	catch (const std::exception & e) {
		std::cout << e.what() << std::endl;
	}
	return;
}

void ScalarConverter::convertInt(const std::string &str) {
	char *float_end_ptr;
	char *long_end_ptr;
	std::cout << "int: ";
	try {
		if (isSpecial(str)) {
			throw ImpossibleException();
		}
		std::strtof(str.c_str(), &float_end_ptr);
		errno = 0;
		long number = std::strtol(str.c_str(), &long_end_ptr, 10);
		if (*long_end_ptr != '\0' && *float_end_ptr != '\0') {
			throw ImpossibleException();
		}
		if (errno == ERANGE || number == LONG_MAX || number == LONG_MIN) {
			throw ImpossibleException();
		}
		if (number < INT_MIN || number > INT_MAX) {
			throw ImpossibleException();
		}
		std::cout << static_cast<int>(number) << std::endl;
	} 
	catch (const std::exception & e) {
		std::cout << e.what() << std::endl;
	}
	return;
}

void ScalarConverter::convertFloat(const std::string &str) {
	std::cout << "float: ";
	(void)str;
	try {
		std::cout << "in process" << std::endl;
	} 
	catch (const std::exception & e) {
		std::cout << e.what() << std::endl;
	}
	return;
}

void ScalarConverter::convertDouble(const std::string &str) {
	(void)str;
	std::cout << "double: ";
	try {
		std::cout << "in process" << std::endl;
	} 
	catch (const std::exception & e) {
		std::cout << e.what() << std::endl;
	}
	return;
}

void ScalarConverter::convert(const std::string &str) {
	ScalarConverter::convertChar(str);
	ScalarConverter::convertInt(str);
	ScalarConverter::convertFloat(str);
	ScalarConverter::convertDouble(str);
}

const char *ScalarConverter::NonPrintableException::what() const throw() {
	return ("Non displayable");
}

const char *ScalarConverter::ImpossibleException::what() const throw() {
	return ("impossible");
}
