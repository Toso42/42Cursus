#ifndef TEMPLATES_TPP
# define TEMPLATES_TPP
#include "includes.hpp"
#include "types.hpp"

// template<typename VarType>
// void addone(VarType& V)
// {
// 	V += 1;
// }

// template<typename VarType, typename VarArg>
// void iter(VarType* ptr, size_t size, void (*function)(VarArg))
// {
// 	for (size_t x = 0; x < size; x++)
// 	{
// 		function(ptr[x]);
// 	}
// }

// template<typename A>
// void print(A* ptr, size_t size)
// {
// 	std::cout << "#	";
// 	for (size_t x = 0; x < size; x++)
// 	{
// 		std::cout << ptr[x];
// 	}
// 	std::cout << std::endl;
// }

template<typename T>
class TArray 
{
private:
	T*		_content;
	size_t	_size;
public:
	TArray(void) : _size(0) {}
	TArray(size_t n) {
		this->_content = new T[n];
		this->_size = n;
	}
	TArray(const TArray& instance) {
		this->_content = new T[instance.size()];
		for (size_t x = 0; x < instance.size(); x++) {
			this->_content[x] = instance[x];
		}
		this->_size = instance.size();
	}
	~TArray() {}
	// operators
	TArray& operator=(const TArray& instance) {
		if (this == instance)
			return (*this);
		delete(this->_content);
		new T[instance.size()];
		for (size_t x = 0; x < instance.size(); x++) {
			this->_content[x] = instance[x];
		}
		this->_size = instance.size();
		return (*this);
	}
	T &operator[](size_t index) const {
		if (index >= this->size())
			throw OutOfBounds();
		return (this->_content[index]);
	}
	// methods
	size_t size() const {
		return(this->_size);
	}

	//exceptions
	class OutOfBounds : public std::exception {
	public:
		virtual const char *what() const throw() {
			return("Error: Trying to access OutOfBounds Memory");
		}
	};	
};

template<typename T>
std::ostream& operator<<(std::ostream& output, const TArray<T>& instance)
{
	for (size_t x = 0; x < instance.size(); x++) {
		output << static_cast<T>(instance[x]);
	}
	return (output);
}

#endif