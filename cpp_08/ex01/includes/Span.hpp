#pragma once
#include <climits>
#include <exception>
#include <vector>

class Span
{
  private:
    unsigned int n_;
    std::vector<unsigned int> data_;
    bool is_sorted_;

  public:
    Span();
    Span(unsigned int n);
    Span(const Span &copy);
    Span &operator=(const Span &copy);
    ~Span();

    void addNumber(unsigned int number);
    unsigned int shortestSpan();
    unsigned int longestSpan();
    void show() const;

    class StoreLimitException : public std::exception
    {
      public:
        virtual const char *what() const throw();
    };
    class NoSpanException : public std::exception
    {
      public:
        virtual const char *what() const throw();
    };
    class UnmatchTypeException : public std::exception
    {
      public:
        virtual const char *what() const throw();
    };

    template <typename Iterator> void addRange(Iterator begin, Iterator end)
    {
        std::size_t range_size = std::distance(begin, end);
        if (this->data_.size() + range_size > n_)
        {
            throw StoreLimitException();
        }
        while (begin != end)
        {
            long long value = static_cast<long long>(*begin);
            if (value < 0 || value > UINT_MAX)
            {
                throw UnmatchTypeException();
            }
            this->addNumber(static_cast<unsigned int>(value));
            ++begin;
        }
        this->is_sorted_ = false;
    }
};
