#pragma once

#include <cerrno>
#include <climits>
#include <cmath>
#include <cstdlib>
#include <string>
// #include <iostream>

class ScalarConverter
{
  private:
    ScalarConverter();
    ScalarConverter(const ScalarConverter &copy);
    ScalarConverter &operator=(const ScalarConverter &copy);
    ~ScalarConverter();
    static void convertChar(const std::string &str);
    static void convertInt(const std::string &str);
    static void convertFloat(const std::string &str);
    static void convertDouble(const std::string &str);

  public:
    static void convert(const std::string &str);
    class NonPrintableException : public std::exception
    {
      public:
        virtual const char *what() const throw();
    };
    class ImpossibleException : public std::exception
    {
      public:
        virtual const char *what() const throw();
    };
};
