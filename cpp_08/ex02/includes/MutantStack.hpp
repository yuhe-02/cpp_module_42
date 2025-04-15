#pragma once


#include <stack>

// TODO add logic
template <typename T>
class MutantStack: public std::stack<T>
{
	public:
		typedef typename std::stack<T>::container_type::iterator iterator;
		MutantStack();
		~MutantStack();
		MutantStack(const MutantStack &other);
		MutantStack &operator=(const MutantStack &other);
		iterator begin();
		iterator end();
};
#include "../templates/MutantStack.tpp"
