#ifndef BASE_HPP
# define BASE_HPP
# include "includes.hpp"
# include "classes.hpp"

class Base 
{
private:
public:
	virtual ~Base(); // if not virtual polimortphysm for inheriting class would not make it possible to make the derived class to be pointed or referenced by a Base class ptr or ref.
};

std::ostream &operator<<(std::ostream &output, const Base &instance);

#endif