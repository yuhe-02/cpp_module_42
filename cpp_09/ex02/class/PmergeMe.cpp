#include "../includes/PmergeMe.hpp"
#include <iostream>
#include <sstream>
#include <vector>

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

void PmergeMe::merge_insert(std::vector<int>& arr, int l, int mid, int r) 
{
	std::cout << "index: [l, mid, r] = [" 
		<< l << ", " << (l + r) / 2 
		<< ", " << r << "]" << " "
		<< "merge-insert: [" 
		<< arr[l] << ", "
		<< arr[mid] << ", "
		<< arr[r] << "]" << std::endl;
}

void PmergeMe::merge_insertion_sort(std::vector<int>& arr, int l, int r) 
{
	if (r - l <= 1)
	{
		return;
	}
    int mid = (l + r) / 2;
	std::cout << "index: [l, mid, r] = [" << l << ", " << (l + r) / 2 << ", " << r << "]" << std::endl;
    this->PmergeMe::merge_insertion_sort(arr, mid, r);
    this->PmergeMe::merge_insertion_sort(arr, l, mid);
    this->PmergeMe::merge_insert(arr, l, mid, r);
}

void PmergeMe::execute_sort(const int* array, const int size)
{
	int end = (size - (size % 2));
    std::vector<int> array_vec(array, array + size);
	std::cout << "[";
	for (std::vector<int>::iterator it = array_vec.begin(); it != array_vec.end(); ++it)
	{
		if (it == array_vec.begin())
			std::cout << *it;
		else
			std::cout << ", " << *it;
	}
	std::cout << "]" << std::endl;

	this->merge_insertion_sort(array_vec, 0, end);
	std::cout << "[";
	for (std::vector<int>::iterator it = array_vec.begin(); it != array_vec.end(); ++it)
	{
		if (it == array_vec.begin())
			std::cout << *it;
		else
			std::cout << ", " << *it;
	}
	std::cout << "]" << std::endl;
}

const char* PmergeMe::InvalidInput::what() const throw()
{
	return ("Invalid input");
}