#include "../includes/whatever.hpp"
#include <iostream>

int main() {
  {
    int a = 2;
    int b = 3;

    std::cout << "a: " << a << ", b: " << b << std::endl;
    ::swap(a, b);
    std::cout << "After swap, a: " << a << ", b: " << b << std::endl;

    std::cout << "Min of a and b: " << ::min(a, b) << std::endl;
    std::cout << "Max of a and b: " << ::max(a, b) << std::endl;
  }

  {
    std::string str1 = "Hello";
    std::string str2 = "World";

    std::cout << "str1: " << str1 << ", str2: " << str2 << std::endl;
    ::swap(str1, str2);
    std::cout << "After swap, str1: " << str1 << ", str2: " << str2
              << std::endl;

    std::cout << "Min of str1 and str2: " << ::min(str1, str2) << std::endl;
    std::cout << "Max of str1 and str2: " << ::max(str1, str2) << std::endl;
  }

  {
    float x = 5.5f;
    float y = 10.5f;

    std::cout << "x: " << x << ", y: " << y << std::endl;
    ::swap(x, y);
    std::cout << "After swap, x: " << x << ", y: " << y << std::endl;

    std::cout << "Min of x and y: " << ::min(x, y) << std::endl;
    std::cout << "Max of x and y: " << ::max(x, y) << std::endl;
  }
  return (0);
}