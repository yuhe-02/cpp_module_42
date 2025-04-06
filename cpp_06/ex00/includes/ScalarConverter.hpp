#pragma once

#include <string>
// #include <iostream>

// TODO fix this(インスタンス化できなくしてもいいのかな)
class ScalarConverter
{
private:

public:
	ScalarConverter();
	ScalarConverter(const ScalarConverter &copy);
	ScalarConverter &operator=(const ScalarConverter & copy);
	~ScalarConverter();
	static void convert(const std::string &str);
};

// std::ostream& operator<<(std::ostream& os, const ScalarConverter& ScalarConverter);
// std::ostream& operator<<(std::ostream& os, const ScalarConverter* ScalarConverter);
