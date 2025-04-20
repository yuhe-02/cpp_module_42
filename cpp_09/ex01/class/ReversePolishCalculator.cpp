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

double ReversePolishCalculator::calculate(const std::string &formula)
{
	std::stack<double> data;
	std::stringstream ss(formula);
	std::string token;

	while (ss >> token)
	{
		std::stringstream token_ss(token);
		double number;
		if (token_ss >> number)
		{
			if (number >= 10)
			{
				std::cout << "over value" << std::endl;
				return 0;
			}
			data.push(number);
		}
		else if (is_operator(token))
		{
			if (data.size() < 2)
			{
				std::cout << "lack data" << std::endl;
				return 0;
			}
			double b = data.top(); data.pop();
			double a = data.top(); data.pop();
			if (token == "+")
			{
				data.push(a + b);
			}
			else if (token == "-")
			{
				data.push(a - b);
			}
			else if (token == "*")
			{
				data.push(a * b);
			}
			else if (token == "/")
			{
				if (b == 0)
				{
					std::cout << "cannot divided by zero" << std::endl;
					return (0);
				}
				data.push(a / b);
			}
		}
		else 
		{
			std::cout << "forbidden literal" << std::endl;
			return 0;
		}
	}
	if (data.size() == 1)
	{
		double result = data.top();
		std::cout << "result: " << result << std::endl;
		return (result);
	} 
	else 
	{
		std::cout << "syntax error" << std::endl;
		return (0);
	}
}
bool is_operator(const std::string &str)
{
	return (str == "+" || str == "-" || str == "*" || str == "/");
}
