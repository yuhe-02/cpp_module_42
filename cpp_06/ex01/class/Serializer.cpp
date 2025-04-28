#include "Serializer.hpp"
#include <iostream>

Serializer::Serializer()
{
    std::cout << "Serializer "
              << "default constructor called" << std::endl;
}

Serializer::~Serializer()
{
    std::cout << "Serializer "
              << "default destructor called" << std::endl;
}

Serializer::Serializer(const Serializer &copy)
{
    (void)copy;
    std::cout << "Serializer "
              << "copy constructor called" << std::endl;
}

Serializer &Serializer::operator=(const Serializer &copy)
{
    std::cout << "Serializer "
              << "copy assignment called" << std::endl;
    if (this == &copy)
        return *this;
    return *this;
}

uintptr_t Serializer::serialize(Data *ptr)
{
    std::cout << "Serializer "
              << "serialize function called" << std::endl;
    return reinterpret_cast<uintptr_t>(ptr);
}

Data *Serializer::deserialize(uintptr_t raw)
{
    std::cout << "Serializer "
              << "deserialize function called" << std::endl;
    return reinterpret_cast<Data *>(raw);
}
