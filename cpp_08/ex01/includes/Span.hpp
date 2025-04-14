#pragma once

// #include <string>
// #include <iostream>
#include <list>
#include <climits>

class Span
{
private:
	unsigned int size_;
	unsigned int n_;
	unsigned int min_span_;
	unsigned int max_span_;
	std::list<unsigned int> *data_;
public:
	Span();
	Span(unsigned int n_);
	Span(const Span &copy);
	Span &operator=(const Span & copy);
	~Span();
	void addNumber(unsigned int number);
	void show();
	unsigned int shortestSpan();
	unsigned int longestSpan();
	class SpanException : public std::exception { 
		public:
			virtual const char *what() const throw() = 0;
	};
	class StoreLimitException: public SpanException { 
		public:
			virtual const char *what() const throw();
	};
	class NoSpanException : public SpanException { 
		public:
			virtual const char *what() const throw();
	};
};

// std::ostream& operator<<(std::ostream& os, const Span& Span);
// std::ostream& operator<<(std::ostream& os, const Span* Span);
