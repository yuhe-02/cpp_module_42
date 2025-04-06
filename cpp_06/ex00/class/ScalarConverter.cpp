#include "ScalarConverter.hpp"
#include <iostream>

ScalarConverter::ScalarConverter() {
	std::cout << "ScalarConverter " << "default constructor called" << std::endl;
}

ScalarConverter::~ScalarConverter() {
	std::cout << "ScalarConverter " << "default destructor called" << std::endl;
}

ScalarConverter::ScalarConverter(const ScalarConverter &copy) {
	std::cout << "ScalarConverter " << "copy constructor called" << std::endl;
	// TODO fix this
	(void)copy;

}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &copy) {
	std::cout << "ScalarConverter " << "copy assignment called" << std::endl;
	(void)copy;
	// TODO fix this
	return *this;
}

void ScalarConverter::convert(const std::string &str) {
	std::cout << "ScalarConverter " << "convert function called" << std::endl;
	(void)str;
	// TODO add logic
	// Conversion logic goes here
}
