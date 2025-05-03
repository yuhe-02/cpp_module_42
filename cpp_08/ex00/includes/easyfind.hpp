#pragma once

#include <algorithm>

class NotFoundException : public std::exception
{
	public:
		virtual const char *what() const throw();
};

template <typename T> 
typename T::iterator easyfind(T &container, int number);

#include "../templates/easyfind.tpp"