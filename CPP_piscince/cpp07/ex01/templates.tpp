#ifndef TEMPLATES_TPP
# define TEMPLATES_TPP
#include "includes.hpp"
#include "types.hpp"

template<typename VarType>
void addone(VarType& V)
{
	V += 1;
}

template<typename VarType, typename VarArg>
void iter(VarType* ptr, size_t size, void (*function)(VarArg))
{
	for (size_t x = 0; x < size; x++)
	{
		function(ptr[x]);
	}
}

template<typename A>
void print(A* ptr, size_t size)
{
	std::cout << "#	";
	for (size_t x = 0; x < size; x++)
	{
		std::cout << ptr[x];
	}
	std::cout << std::endl;
}

#endif