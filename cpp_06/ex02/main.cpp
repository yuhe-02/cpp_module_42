#include <iostream>
#include "base_service.hpp"
#include <ctime> 

int main() {
	{
		std::cout << "----normal test----" << std::endl;
		Base *base = generate();
		Base *ref = 0;
		Base &ref2 = *ref;

		identify(base);
		identify(*base);
		identify(ref);
		identify(ref2);
		
		delete base;
	}
	return (0);
}