#include "Span.hpp"
#include <iostream>

Span::Span(): size_(0), n_(10000), min_span_(UINT_MAX), max_span_(0), data_(new std::list<unsigned int>) {
	std::cout << "Span " << "default constructor called" << std::endl;
}

Span::Span(unsigned int n): size_(0), n_(n), min_span_(UINT_MAX), max_span_(0), data_(new std::list<unsigned int>) {
	std::cout << "Span " << "constructor with arg called" << std::endl;
}

Span::~Span() {
	std::cout << "Span " << "default destructor called" << std::endl;
	delete this->data_;
}

Span::Span(const Span &copy): size_(copy.size_), n_(copy.n_), min_span_(copy.min_span_), max_span_(copy.max_span_), data_(new std::list<unsigned int>) {
	std::cout << "Span " << "copy constructor called" << std::endl;
	for (std::list<unsigned int>::iterator i = copy.data_->begin(); i != copy.data_->end(); i++)
	{
		this->data_->push_back(*i);
	}
}

Span &Span::operator=(const Span &copy) {
	std::cout << "Span " << "copy assignment called" << std::endl;
	if (this == &copy)
	{
		return *this;
	}
	if (this->data_)
	{
		delete this->data_;
	}
	this->size_ = copy.size_;
	this->n_ = copy.n_;
	this->min_span_ = copy.min_span_;
	this->max_span_ = copy.max_span_;
	this->data_ = new std::list<unsigned int >;
	for (std::list<unsigned int >::iterator i = copy.data_->begin(); i != copy.data_->end(); i++)
	{
		this->data_->push_back(*i);
	}
	return *this;
}

void Span::addNumber(unsigned int number)
{
	if (this->size_ == this->n_)
	{
		throw StoreLimitException();
	}
	std::list<unsigned int>::iterator it = this->data_->begin();
	while (it != this->data_->end() && *it < number)
		++it;
	it = this->data_->insert(it, number);
	this->size_ += 1;
	if (this->size_ >=2) {
		std::list<unsigned int>::iterator last = this->data_->end();
		std::list<unsigned int>::iterator first = this->data_->begin();
		--last;
		this->max_span_ = *last - *first;
		if (it != first)
		{
			std::list<unsigned int>::iterator back = it;
			--back;
			unsigned int span = *it - *back;
			if (this->min_span_ > span)
			{
				this->min_span_ = span;
			}
		} 
		if (++it != this->data_->end()) {
			unsigned int span = *it - *(--it);
			if (span < this->min_span_)
			{
				this->min_span_ = span;
			}
		}
	}
}

unsigned int Span::shortestSpan()
{
	if (this->size_ <= 1)
	{
		throw NoSpanException();
	}
	return this->min_span_;
}
unsigned int Span::longestSpan()
{
	if (this->size_ <= 1)
	{
		throw NoSpanException();
	}
	return this->max_span_;
}

void Span::show()
{
	std::cout << "[";
	for (std::list<unsigned int >::iterator i = this->data_->begin(); i != this->data_->end(); i++)
	{
		if (i != this->data_->begin())
		{
			std::cout << ",";
		}
		std::cout << *i;
	}
	std::cout << "]" << std::endl;
}

const char *Span::NoSpanException::what() const throw() {
	return ("no span found");
}

const char *Span::StoreLimitException::what() const throw() {
	return ("store limit reached");
}
