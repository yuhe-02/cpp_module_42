#pragma once

// #include <string>
// #include <iostream>

class C
{
private:

public:
	C();
	C(const C &copy);
	C &operator=(const C & copy);
	~C();
};

// std::ostream& operator<<(std::ostream& os, const C& C);
// std::ostream& operator<<(std::ostream& os, const C* C);
