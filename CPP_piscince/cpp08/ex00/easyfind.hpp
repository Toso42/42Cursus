#include "includes.hpp"
#include "types.hpp"

// The compiler, during template instantiation stage, will instantiate templates.
// Typically a typename may refer to a type of variable. In this example we have
// typenames referring to DEPENDENT names, such as Container::iterator.
// Since compiler doesn't know the type of container beforehand, we need to tell
// the compiler to FILL the container::iterator name referring to the
// typename Container definition in the template declaration.
// By the time i am writing this this seems like black magic to me, and this level
// of abstraction kinda sickens me. It will be fun for me to read this in a few years.

// *All this code is written in the c++98 standard. It is my undesrtanding that the
// std::iterator base class has been deprecated since c++17. This shouldn't affect
// this code, because my template is referring to the container's type inner iterator
// member and implementation, and not to the std::iterator general class type. I hope.

template<typename Container, typename T>
typename Container::iterator easyfind(Container& containter, const T tofind)
{
    typename Container::iterator   begin = containter.begin();
    typename Container::iterator   end = containter.end();
    typename Container::iterator   it = find(begin, end, tofind);

    if (it != end) {
        std::cout << "easyfind: element found." << std::endl;
        return(it);
    }
    else {
		throw std::out_of_range("easyfind: element NOT found.");
    }
}

