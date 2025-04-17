#include <iostream>
#include <string>
#include "./includes/ReversePolishCalculator.hpp"

int main(int argc, char **argv) 
{
	(void)argv;
	if (argc != 2)
	{
		std::cerr << "Bad argument" << std::endl;
		return (0);
	}
	try
	{
		ReversePolishCalculator rpn;
		int res = rpn.calculate(std::string(argv[1]));
		std::cout << res << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	return (0);
}