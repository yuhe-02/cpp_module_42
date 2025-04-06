#pragma once

// #include <string>
// #include <iostream>

class Span
{
private:

public:
	Span();
	Span(const Span &copy);
	Span &operator=(const Span & copy);
	~Span();
};

// std::ostream& operator<<(std::ostream& os, const Span& Span);
// std::ostream& operator<<(std::ostream& os, const Span* Span);
