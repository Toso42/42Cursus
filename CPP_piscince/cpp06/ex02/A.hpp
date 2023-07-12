#ifndef A_HPP
# define A_HPP
# include "includes.hpp"
# include "classes.hpp"

class A : public Base
{
};

std::ostream& operator<<(std::ostream& output, const A& instance);
#endif