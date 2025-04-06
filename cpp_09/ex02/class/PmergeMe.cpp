#include "../includes/PmergeMe.hpp"
#include <iostream>

PmergeMe::PmergeMe() {
	std::cout << "PmergeMe " << "default constructor called" << std::endl;
}

PmergeMe::~PmergeMe() {
	std::cout << "PmergeMe " << "default destructor called" << std::endl;
}

PmergeMe::PmergeMe(const PmergeMe &copy) {
	std::cout << "PmergeMe " << "copy constructor called" << std::endl;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &copy) {
	std::cout << "PmergeMe " << "copy assignment called" << std::endl;
	if (this == &copy)
		return *this;
	return *this;
}
