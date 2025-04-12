#include <iostream>
#include "base_service.hpp"
#include <ctime> 

int main() {
	{
		std::cout << "----normal test----" << std::endl;
		Base *base = generate();
		identify(base);
		identify(*base);
		delete base;
	}
	return (0);
}