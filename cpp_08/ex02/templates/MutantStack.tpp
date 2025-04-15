
template <typename T>
MutantStack<T>::MutantStack()
{
	std::cout << "MutantStack: " << "Default Constructor called" << std::endl;
}


template <typename T>
MutantStack<T>::~MutantStack()
{
	std::cout << "MutantStack: " << "Destructor called" << std::endl;
}

template <typename T>
MutantStack<T>::MutantStack(const MutantStack<T> &other): std::stack<T>(other)
{
	std::cout << "MutantStack: " << "Copy Constructor called" << std::endl;
}

template <typename T>
MutantStack<T> &MutantStack<T>::operator=(const MutantStack<T> &other)
{
	std::stack<T>::operator=(other);
	std::cout << "MutantStack: " << "Copy Assignment called" << std::endl;
	return *this;
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::begin()
{
	return this->c.begin();
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::end()
{
	return this->c.end();
}