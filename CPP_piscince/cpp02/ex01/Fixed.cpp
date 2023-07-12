#include <iostream>
#include "Fixed.hpp"
#include <cmath>

Fixed::Fixed()
{
	this->setRawBits(0);
}

Fixed::Fixed(const int value)
{
	int	local = value;
	local <<= this->getBits();
	this->setRawBits(local);
}

Fixed::Fixed(const float value)
{
	int local = roundf(value * (1 << this->getBits()));
	//std::cout << "here" << local << std::endl;
	this->setRawBits(local);
}

//copy constructor
Fixed::Fixed(const Fixed &ptr)
{
	this->_value = ptr.getRawBits();
}

// operator overload
Fixed& Fixed::operator=(const Fixed& instance)
{
	if (this != &instance)
		_value = instance.getRawBits();
	return (*this);
}

std::ostream& operator<<(std::ostream &output, const Fixed &instance)
{
	output << instance.toFloat();
	return (output);
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const
{
	return(this->_value);
}

void Fixed::setRawBits(const int value)
{
	this->_value = value;
}

int Fixed::toInt(void) const
{
	return((int)this->toFloat());
}

float Fixed::toFloat(void) const
{
	return(((float)this->getRawBits()) / (1 << this->getBits()));
}

int Fixed::getBits(void) const
{
	return(this->_bits);
}



//