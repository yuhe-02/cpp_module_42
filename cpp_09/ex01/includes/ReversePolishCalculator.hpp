#pragma once

#include <sstream>
#include <stack>
#include <string>
// #include <iostream>
// TODO スタックで行けそう

bool is_operator(const std::string &str);
class ReversePolishCalculator {
private:
  ReversePolishCalculator(const ReversePolishCalculator &copy);
  ReversePolishCalculator &operator=(const ReversePolishCalculator &copy);
  ~ReversePolishCalculator();
  ReversePolishCalculator();

public:
  static double calculate(const std::string &formula);
};

// std::ostream& operator<<(std::ostream& os, const ReversePolishCalculator&
// ReversePolishCalculator); std::ostream& operator<<(std::ostream& os, const
// ReversePolishCalculator* ReversePolishCalculator);
