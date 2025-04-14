#include "../includes/Span.hpp"
#include <iostream>
#include <algorithm>
#include <climits>

Span::Span() : n_(10000), is_sorted_(false) {
	std::cout << "Span default constructor called" << std::endl;
}

Span::Span(unsigned int n) : n_(n), is_sorted_(false) {
	std::cout << "Span constructor with arg called" << std::endl;
}

Span::Span(const Span &copy)
	: n_(copy.n_), data_(copy.data_), is_sorted_(copy.is_sorted_) {
	std::cout << "Span copy constructor called" << std::endl;
}

Span &Span::operator=(const Span &copy) {
	std::cout << "Span copy assignment called" << std::endl;
	if (this != &copy) {
		this->n_ = copy.n_;
		this->data_ = copy.data_;
		this->is_sorted_ = copy.is_sorted_;
	}
	return *this;
}

Span::~Span() {
	std::cout << "Span destructor called" << std::endl;
}

void Span::addNumber(unsigned int number) {
	if (this->data_.size() >= n_)
		throw StoreLimitException();
	this->data_.push_back(number);
	is_sorted_ = false;
}

unsigned int Span::shortestSpan() {
	if (this->data_.size() < 2)
		throw NoSpanException();
	if (!is_sorted_) {
		std::sort(this->data_.begin(), this->data_.end());
		is_sorted_ = true;
	}
	unsigned int min_span = UINT_MAX;
	for (size_t i = 1; i < this->data_.size(); ++i) {
		unsigned int diff = this->data_[i] - this->data_[i - 1];
		if (diff < min_span)
			min_span = diff;
	}
	return min_span;
}

unsigned int Span::longestSpan() {
	if (this->data_.size() < 2)
		throw NoSpanException();
	if (!is_sorted_) {
		std::sort(this->data_.begin(), this->data_.end());
		is_sorted_ = true;
	}
	return this->data_.back() - this->data_.front();
}

void Span::show() const {
	std::cout << "[";
	for (size_t i = 0; i < this->data_.size(); ++i) {
		if (i != 0) std::cout << ",";
		std::cout << this->data_[i];
	}
	std::cout << "]" << std::endl;
}

const char *Span::StoreLimitException::what() const throw() {
	return "store limit reached";
}

const char *Span::NoSpanException::what() const throw() {
	return "no span found";
}

const char *Span::UnmatchTypeException::what() const throw() {
	return "unmatched value. value must be unsigned int";
}
