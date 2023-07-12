#include "includes.hpp"
#include "classes.hpp"

Serializer::Serializer()
{
    std::cout << "Static class Serializer loaded" << std::endl;
}

Serializer::Serializer(const Serializer& instance)
{
    (void)instance;
    std::cout << "Serializer (static type) copy constructor called (pointless)" << std::endl;
}

Serializer& Serializer::operator=(const Serializer& instance)
{
    (void)instance;
    return (*this);
}

Serializer::~Serializer()
{
    std::cout << "Serializer Deconstructor called." << std::cout;
}

uintptr_t Serializer::serialize(Data* ptr)
{
    return (reinterpret_cast<uintptr_t>(ptr));
}

Data* Serializer::deserialize(uintptr_t raw)
{
    return (reinterpret_cast<Data*>(raw));
}
