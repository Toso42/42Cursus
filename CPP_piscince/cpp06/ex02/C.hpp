#ifndef C_HPP
# define C_HPP
# include "includes.hpp"
# include "classes.hpp"

class C : public Base
{
};

std::ostream& operator<<(std::ostream& output, const C& instance);
#endif