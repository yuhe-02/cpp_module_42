#pragma once

#include <string>
// #include <iostream>

class PmergeMe
{
private:
	PmergeMe();
	PmergeMe(const PmergeMe &copy);
	PmergeMe &operator=(const PmergeMe & copy);
	~PmergeMe();
public:
	static int 	convert_positive_int(const std::string& str);
	static int* create_numbers(char **str_ptr, int size);
};
// std::ostream& operator<<(std::ostream& os, const PmergeMe& PmergeMe);
// std::ostream& operator<<(std::ostream& os, const PmergeMe* PmergeMe);
