#pragma once

#include <string>
#include <stdint.h>
// #include <iostream>

struct Data {
    int id;
    std::string name;
};

class Serializer
{
private:
	Serializer();
	Serializer(const Serializer &copy);
	Serializer &operator=(const Serializer & copy);
	~Serializer();
public:
	static uintptr_t serialize(Data* ptr);
	static Data* deserialize(uintptr_t raw);

};
