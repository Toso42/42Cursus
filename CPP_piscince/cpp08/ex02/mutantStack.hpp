#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP
# include "includes.hpp"
# include "types.hpp"

template < typename T, typename Container = std::deque<T> >
class MutantStack : public std::stack<T, Container>
{
	private:
		// empty

	public:
		MutantStack(void) {};
		MutantStack(MutantStack<T, Container> const &to_copy) : std::stack<T, Container>(to_copy) {};
		virtual ~MutantStack(void) {};
		MutantStack<T, Container>	&operator=(MutantStack<T, Container> const &to_copy)
		{
			if (this != &to_copy)
				*this = std::stack<T, Container>(to_copy);
			return (*this);
		}

        // note that if an explicit container not having an iterator member is used, it will
        // fail at compilation. in C++11 we could circumvent this with a static_assert statement
        // and throw an exception in such a case, in C++98 we should make many specialized templates
        // for the MutantSstack with different containers, a very inconvenient job.
		typedef typename Container::iterator	iterator;
		iterator		begin(void)
		{
			return (this->c.begin());
		}
		iterator		end(void)
		{
			return (this->c.end());
		}
};

#endif