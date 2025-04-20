template <typename T>
Array<T>::Array() : data_(NULL), size_(0) 
{
	std::cout << "Array: Default Constructor called." << std::endl;
}

template <typename T>
Array<T>::Array(unsigned int size) : data_(new T[size]()), size_(size) 
{
	std::cout << "Array: Constructor with argument called." << std::endl;
}

template <typename T>
Array<T>::Array(const Array &copy) : data_(copy.size() == 0 ? NULL : new T[copy.size()]()), size_(copy.size()) 
{
	std::cout << "Array: Copy Constructor called." << std::endl;
	for (unsigned int i = 0; i < this->size_; ++i)
		this->data_[i] = copy.data_[i];
}

template <typename T>
Array<T> &Array<T>::operator=(const Array &copy)
{
	std::cout << "Array: Copy assignment called." << std::endl;
	if (this == &copy)
	{
		return *this;
	}
	if (this->data_ != NULL)
	{
		delete[] this->data_;
	}
	this->size_ = copy.size();
	this->data_ = (size_ == 0) ? NULL : new T[this->size_]();
	for (unsigned int i = 0; i < this->size_; ++i)
	{
		this->data_[i] = copy.data_[i];
	}
	return *this;
}

template <typename T>
Array<T>::~Array() 
{
	std::cout << "Array: Destructor called." << std::endl;
	if (this->data_ != NULL)
	{
		delete[] data_;
	}
}

template <typename T>
T &Array<T>::operator[](unsigned int index) 
{
	if (index >= this->size_)
	{
		throw OutOfBounds();
	}
	return this->data_[index];
}

template <typename T>
const T &Array<T>::operator[](unsigned int index) const 
{
	if (index >= this->size_)
	{
		throw OutOfBounds();
	}
	return this->data_[index];
}

template <typename T>
unsigned int Array<T>::size() const 
{
	return this->size_;
}

template <typename T>
const char* Array<T>::OutOfBounds::what() const throw()
{
	return "Index out of bounds";
}


