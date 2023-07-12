# include "includes.hpp"
# include "types.hpp"

// Span::Span()
// {
// 	this->_maxSize = 0;
// }

Span::Span(const Span& instance)
{
	this->_maxSize = instance.getSize();
	this->_array = instance.getArray();

}

Span& Span::operator=(const Span& instance)
{
	this->_maxSize = instance.getSize();
	this->_array = instance.getArray();	
	return *this;
}

Span::~Span()
{
		
}

void Span::addNumber(int N)
{
	if (this->_array.size() >= this->_maxSize)
		throw(SpanAlreadyFilled());
	this->_array.push_back(N);
}

std::size_t Span::shortestSpan()
{
	std::size_t curSpan;
	if (this->_array.size() <= 1)
		throw(EmptyRange());
	for (size_t i = 0; i < this->_array.size(); i++)
	{
		curSpan = abs(this->_array[i] - this->_array[i - 1]);
		if ( curSpan < this->_shortSpan)
			this->_shortSpan = curSpan;
	}
	return (this->_shortSpan);
}

std::size_t Span::longestSpan()
{
	std::size_t curSpan;
	if (this->_array.size() <= 1)
		throw(EmptyRange());
	this->_longSpan = 0;

	for (size_t i = 1; i < this->_array.size(); i++)
	{
		curSpan = abs(this->_array[i] - this->_array[i - 1]);
		if ( curSpan > this->_longSpan)
			this->_longSpan = curSpan;
	}
	return (this->_longSpan);
}

void Span::fillRange(std::vector<int>::iterator from, std::vector<int>::iterator to)
{
	std::size_t	vec_size = 0;
	std::vector<int>::iterator begincpy = from;

	while (begincpy != to)
	{
		vec_size++;
		begincpy++;
	}

	if (this->_array.size() + vec_size > this->getSize())
		throw(RangeTooBig());
	this->_array.insert(this->_array.end(), from, to);
}

std::vector<int> Span::getArray() const
{
	return(this->_array);
}

std::size_t Span::getSize() const
{
	return(this->_maxSize);
}

std::ostream& operator<<(std::ostream& output, const Span& instance)
{
	std::vector<int> vec = instance.getArray();
	for (size_t i = 0; i < vec.size(); i++)
	{
		output << vec[i] << " ";
	}
	output << std::endl;
	return(output);
	
}

