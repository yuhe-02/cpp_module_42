#pragma once

#include <string>

// #include <iostream>
// TODO スタックで行けそう
class ReversePolishCalculator
{
	private:
		ReversePolishCalculator(const ReversePolishCalculator &copy);
		ReversePolishCalculator &operator=(const ReversePolishCalculator & copy);
	public:
		ReversePolishCalculator();
		int calculate(std::string formula);
		~ReversePolishCalculator();
};

// std::ostream& operator<<(std::ostream& os, const ReversePolishCalculator& ReversePolishCalculator);
// std::ostream& operator<<(std::ostream& os, const ReversePolishCalculator* ReversePolishCalculator);
