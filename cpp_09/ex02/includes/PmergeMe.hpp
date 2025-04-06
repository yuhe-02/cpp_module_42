#pragma once

// #include <string>
// #include <iostream>

class PmergeMe
{
private:

public:
	PmergeMe();
	PmergeMe(const PmergeMe &copy);
	PmergeMe &operator=(const PmergeMe & copy);
	~PmergeMe();
};

// std::ostream& operator<<(std::ostream& os, const PmergeMe& PmergeMe);
// std::ostream& operator<<(std::ostream& os, const PmergeMe* PmergeMe);
