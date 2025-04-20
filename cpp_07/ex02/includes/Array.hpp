#pragma once

#include <iostream>

template <typename T>
class Array {
	private:
		T* data_;
		unsigned int size_;
	public:
		Array();
		Array(unsigned int size);
		Array(const Array &copy);
		Array &operator=(const Array &copy);
		T &operator[](unsigned int index);
		const T &operator[](unsigned int index) const;
		unsigned int size() const;
		~Array();
		class OutOfBounds : public std::exception 
		{
			public:
				virtual const char* what() const throw();
		};
};
// placing after prototype declaration
#include "../templates/Array.tpp"
