#include <iostream>
#include "./includes/iter.hpp"


void add_int(int &value) {
	value += 1;
}

void add_string(std::string &value) {
	value += "_string";
}

void add_float(float &value) {
	value += 0.1;
}

int main() {
	{
		std::cout << "----normal test1----" << std::endl;
		int test_array[] = {1, 2, 3};
		::iter(test_array, sizeof(test_array) / sizeof(test_array[0]), &add_int);
		for (size_t i = 0; i < sizeof(test_array) / sizeof(test_array[0]); ++i) {
			std::cout << test_array[i] << " ";
		}
		std::cout << std::endl;
	}
	{
		std::cout << "----normal test2----" << std::endl;
		float test_array[] = {1, 2, 3};
		::iter(test_array, sizeof(test_array) / sizeof(test_array[0]), &add_float);
		for (size_t i = 0; i < sizeof(test_array) / sizeof(test_array[0]); ++i) {
			std::cout << test_array[i] << " ";
		}
		std::cout << std::endl;
	}
	{
		std::cout << "----normal test3----" << std::endl;
		std::string test_array[] = {"1", "2", "3"};
		::iter(test_array, sizeof(test_array) / sizeof(test_array[0]), &add_string);
		for (size_t i = 0; i < sizeof(test_array) / sizeof(test_array[0]); ++i) {
			std::cout << test_array[i] << " ";
		}
		std::cout << std::endl;
	}
	return (0);
}