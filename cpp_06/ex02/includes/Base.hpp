#pragma once

// #include <string>
// #include <iostream>

class Base
{
private:

public:
	Base();
	Base(const Base &copy);
	Base &operator=(const Base & copy);
	~Base();
};

// std::ostream& operator<<(std::ostream& os, const Base& Base);
// std::ostream& operator<<(std::ostream& os, const Base* Base);
