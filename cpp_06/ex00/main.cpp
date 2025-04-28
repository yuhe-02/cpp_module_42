#include "ScalarConverter.hpp"
#include <iostream>

int main(int ac, char **av) {
  int n;

  if (ac == 1)
    return (0);
  n = 1;
  while (n < ac) {
    std::cout << "Conversion of " << av[n] << ":\n";
    ScalarConverter::convert(*(av + n));
    std::cout << "---------------------------------\n";
    n++;
  }
}