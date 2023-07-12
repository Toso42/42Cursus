#ifndef SPAN_HPP
# define SPAN_HPP
# include "includes.hpp"
# include "types.hpp"

class Span {

	private:
	std::vector<int>	_array; //vectors default empty initialization: this vector has zero size.
	std::size_t		 	_maxSize;
	std::size_t			_shortSpan;
	std::size_t			_longSpan;

	public:
//	Span();
	Span(const Span& instance);
	Span& operator=(const Span& instance);
	~Span();

	Span(std::size_t size) : _maxSize(size) {};

	void				addNumber(int N);
	std::size_t 		shortestSpan();
	std::size_t 		longestSpan();
	void				fillRange(std::vector<int>::iterator from, std::vector<int>::iterator to);
	std::vector<int>	getArray() const;
	std::size_t			getSize() const;

	class SpanAlreadyFilled : public std::exception {
		public:
			virtual const char* what() const throw() {
				return("Can't add another element: Span is full.");
			}
	};
	class RangeTooBig : public std::exception {
		public:
			virtual const char* what() const throw() {
				return("Can't insert a range exceding the Span Max Size");
			}
	};
	class EmptyRange : public std::exception {
		public:
			virtual const char* what() const throw() {
				return("Span Object is Empty");
			}
	};
};

std::ostream& operator<<(std::ostream& output, const Span& instance);

#endif