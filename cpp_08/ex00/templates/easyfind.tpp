#include "easyfind.hpp"

template <typename T>
int &easyfind(T &container, int number) {
	typename T::iterator it = std::find(container.begin(), container.end(), number);
	if (it == container.end())
	{
		throw std::out_of_range("Number not found in container");
	}
	return *it;
}