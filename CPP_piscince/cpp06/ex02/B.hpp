#ifndef B_HPP
# define B_HPP
# include "includes.hpp"
# include "classes.hpp"

class B : public Base
{
};

std::ostream& operator<<(std::ostream& output, const B& instance);
#endif