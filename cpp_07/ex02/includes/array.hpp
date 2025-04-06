#pragma once

// #include <string>
// #include <iostream>

class Template
{
private:

public:
	Template();
	Template(const Template &copy);
	Template &operator=(const Template & copy);
	~Template();
};

// std::ostream& operator<<(std::ostream& os, const Template& Template);
// std::ostream& operator<<(std::ostream& os, const Template* Template);
