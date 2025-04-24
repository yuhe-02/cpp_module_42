#include "../includes/PmergeMe.hpp"
#include <iostream>
#include <sstream>

PmergeMe::PmergeMe() 
{
	std::cout << "PmergeMe " << "default constructor called" << std::endl;
}

PmergeMe::~PmergeMe() 
{
	std::cout << "PmergeMe " << "default destructor called" << std::endl;
}

PmergeMe::PmergeMe(const PmergeMe &copy) 
{
	(void)copy;
	std::cout << "PmergeMe " << "copy constructor called" << std::endl;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &copy) 
{
	(void)copy;
	std::cout << "PmergeMe " << "copy assignment called" << std::endl;
	return *this;
}

int PmergeMe::convert_positive_int(const std::string& str) {
	std::stringstream ss(str);
	int value;
	ss >> value;
	if (ss.fail() || !ss.eof())
	{
		return (-1);
	}
	return (value);
}

int* PmergeMe::create_numbers(char **str_ptr, int size)
{
	int *array = new int[size];
	for (int i = 0; i < size; i++)
	{
		int res = PmergeMe::convert_positive_int(std::string(str_ptr[i]));
		if (res == -1)
		{
			delete[] array;
			throw PmergeMe::InvalidInput();
		}
		array[i] = res;
	}
	return array;
}

const char* PmergeMe::InvalidInput::what() const throw()
{
	return ("Invalid input");
}