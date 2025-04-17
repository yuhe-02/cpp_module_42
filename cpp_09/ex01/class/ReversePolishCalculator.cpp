#include "../includes/ReversePolishCalculator.hpp"
#include <iostream>

ReversePolishCalculator::ReversePolishCalculator() 
{
	std::cout << "ReversePolishCalculator " << "default constructor called" << std::endl;
}

ReversePolishCalculator::~ReversePolishCalculator() 
{
	std::cout << "ReversePolishCalculator " << "default destructor called" << std::endl;
}

ReversePolishCalculator::ReversePolishCalculator(const ReversePolishCalculator &copy) 
{
	(void)copy;
	std::cout << "ReversePolishCalculator " << "copy constructor called" << std::endl;
}

ReversePolishCalculator &ReversePolishCalculator::operator=(const ReversePolishCalculator &copy)
{
	(void)copy;
	std::cout << "ReversePolishCalculator " << "copy assignment called" << std::endl;
	if (this == &copy)
		return *this;
	return *this;
}

int ReversePolishCalculator::calculate(std::string formula)
{
	(void)formula;
	return 42;
}
