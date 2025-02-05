#include <iostream>
#include <fstream>

#include "Sed.hpp"
int main() {
	std::string filename="test";
	std::string s1="A";
	std::string s2="AB";

	try {
		Sed sed(filename, s1, s2);
		sed.executeReplace();
	} catch (const std::runtime_error& e) {
		std::cerr << "Error: " << e.what() << std::endl;
		return (1);
	}
	return (0);
}