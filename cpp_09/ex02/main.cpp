#include <iostream>
#include "./includes/PmergeMe.hpp"
#include <sstream>

void show(int *array, int size)
{
	std::cout << "[";
	for (int i = 0; i < size; i++)
	{
		if (i != 0)
		{
			std::cout << ", ";
		}
		std::cout << array[i];
	}
	std::cout << "]" << std::endl;
}

int main(int argc, char **argv) 
{
	int *array = NULL;
	if (argc < 2)
	{
		std::cerr << "Error" << std::endl;
	}
	try 
	{
		array = PmergeMe::create_numbers(&(argv[1]), argc - 1);
		if (!array)
		{
			std::cerr << "Error" << std::endl;
		}
		else 
		{
			show(array, argc-1);
		}
	}
	catch (const std::exception &e) 
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}
	if (array)
	{
		delete[] array; 
	}
	return (0);
}