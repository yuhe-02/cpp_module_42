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
		double res = ReversePolishCalculator::calculate(std::string(argv[1]));
		std::cout << res << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << "Error" << std::endl;
	}
	return (0);
}