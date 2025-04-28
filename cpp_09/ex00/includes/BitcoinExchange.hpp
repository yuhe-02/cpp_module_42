#pragma once

#include <algorithm>
#include <fstream>
#include <map>
#include <sstream>
#include <string>
class BitcoinExchange
{
  private:
    std::map<std::string, float> data_;
    std::map<std::string, float> _read_rate_file(const std::string &rate_path);
    bool _isValidDate(const std::string &date_str);
    std::string _trimSpace(const std::string &s);
    BitcoinExchange();
    BitcoinExchange(const BitcoinExchange &copy);
    BitcoinExchange &operator=(const BitcoinExchange &copy);

  public:
    BitcoinExchange(const std::string data_path);
    ~BitcoinExchange();
    void show();
    void execute_exchange(const std::string &target_path);
    class FilePermissionException : public std::exception
    {
      public:
        virtual const char *what() const throw();
    };
    class ParseFailException : public std::exception
    {
      public:
        virtual const char *what() const throw();
    };
    class ValueTooHighException : public ParseFailException
    {
      public:
        virtual const char *what() const throw();
    };
    class ValueTooLowException : public ParseFailException
    {
      public:
        virtual const char *what() const throw();
    };
    class BadFormatException : public ParseFailException
    {
      public:
        virtual const char *what() const throw();
    };
    class InvalidDateException : public ParseFailException
    {
      public:
        virtual const char *what() const throw();
    };
    class InvalidNumberException : public ParseFailException
    {
      public:
        virtual const char *what() const throw();
    };
};