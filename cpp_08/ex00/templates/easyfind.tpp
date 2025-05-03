#include "easyfind.hpp"

const char *NotFoundException::what() const throw()
{
  return "Number not found in container";
}

template <typename T> 
typename T::iterator easyfind(T &container, int number)
{
  typename T::iterator it =
      std::find(container.begin(), container.end(), number);
  if (it == container.end())
  {
    throw NotFoundException();
  }
  return it;
}