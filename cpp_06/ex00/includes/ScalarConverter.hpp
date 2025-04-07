#pragma once

#include <string>
// #include <iostream>

// TODO fix this(インスタンス化できなくしてもいいのかな)
class ScalarConverter
{
private:
	ScalarConverter();
	ScalarConverter(const ScalarConverter &copy);
	ScalarConverter &operator=(const ScalarConverter & copy);
	~ScalarConverter();
	static void convertChar(const std::string &str);
public:
	static void convert(const std::string &str);
	class NonPrintableException : public std::exception { 
		public:
			virtual const char *what() const throw();
	};
	class ImpossibleException : public std::exception { 
		public:
			virtual const char *what() const throw();
	};
};

// std::ostream& operator<<(std::ostream& os, const ScalarConverter& ScalarConverter);
// std::ostream& operator<<(std::ostream& os, const ScalarConverter* ScalarConverter);
