#pragma once

// #include <string>
// #include <iostream>

class B
{
private:

public:
	B();
	B(const B &copy);
	B &operator=(const B & copy);
	~B();
};

// std::ostream& operator<<(std::ostream& os, const B& B);
// std::ostream& operator<<(std::ostream& os, const B* B);
