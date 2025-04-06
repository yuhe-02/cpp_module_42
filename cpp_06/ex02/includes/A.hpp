#pragma once

// #include <string>
// #include <iostream>

class A
{
private:

public:
	A();
	A(const A &copy);
	A &operator=(const A & copy);
	~A();
};

// std::ostream& operator<<(std::ostream& os, const A& A);
// std::ostream& operator<<(std::ostream& os, const A* A);
