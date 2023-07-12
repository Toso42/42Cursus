#include "Fixed.hpp"

Fixed::Fixed()
{
	std::cout << "Default Constructor called" << std::endl;
	this->_value = 0;
}

Fixed::Fixed(const Fixed &ptr)
{
	std::cout << "Copy Constructor called" << std::endl;
	this->_value = ptr.getRawBits();
}

Fixed& Fixed::operator=(const Fixed& instance)
{
	std::cout << "Copy assignment operator called // <-- This line may be missing depending on your implementation" << std::endl;
	if (this != &instance)
	{
		_value = instance.getRawBits();
	}//ciao
	return (*this);
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return(this->_value);
}

void Fixed::setRawBits(const int value)
{
	this->_value = value;
}
