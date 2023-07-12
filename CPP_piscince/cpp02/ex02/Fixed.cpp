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
	// std::cout << "here" << local << std::endl;
	this->setRawBits(local);
}

//copy constructor
Fixed::Fixed(const Fixed &ptr)
{
	this->_value = ptr.getRawBits();
}

Fixed::~Fixed()
{
	//std::cout << "Destructor called" << std::endl;
}

//	________________________OPERATORS_________________________ //

bool	Fixed::operator==(const Fixed& instance)
{
	if (this->getRawBits() == instance.getRawBits())
		return(true);
	return(false);
}

bool	Fixed::operator!=(const Fixed& instance)
{
	if (this->getRawBits() != instance.getRawBits())
		return(true);
	return(false);
}

bool	Fixed::operator>(const Fixed& instance)
{
	if (this->getRawBits() > instance.getRawBits())
		return(true);
	return(false);
}

bool	Fixed::operator>=(const Fixed& instance)
{
	if (this->getRawBits() >= instance.getRawBits())
		return(true);
	return(false);
}

bool	Fixed::operator<(const Fixed& instance)
{
	if (this->getRawBits() < instance.getRawBits())
		return(true);
	return(false);
}

bool	Fixed::operator<=(const Fixed& instance)
{
	if (this->getRawBits() <= instance.getRawBits())
		return(true);
	return(false);
}

std::ostream& operator<<(std::ostream &output, const Fixed &instance)
{
	output << instance.toFloat();
	return (output);
}

//________Arithmetic operators

// = operator overload
Fixed& Fixed::operator=(const Fixed& instance)
{
	if (this != &instance)
		_value = instance.getRawBits();
	return (*this);
}

// = operator overload
Fixed Fixed::operator+(const Fixed& instance)
{
	Fixed	Result;
	float	FloatResult;

	FloatResult = this->toFloat() + instance.toFloat();
	Result = Fixed(FloatResult);
	return (Result);
}

Fixed Fixed::operator-(const Fixed& instance)
{
	Fixed	Result;
	float	FloatResult;

	FloatResult = this->toFloat() - instance.toFloat();
	Result = Fixed(FloatResult);
	return (Result);
}

Fixed Fixed::operator*(const Fixed& instance)
{
	Fixed	Result;
	float	FloatResult;

	FloatResult = this->toFloat() * instance.toFloat();
	Result = Fixed(FloatResult);
	return (Result);
}

Fixed Fixed::operator/(const Fixed& instance)
{
	Fixed	Result;
	float	FloatResult;

	FloatResult = this->toFloat() / instance.toFloat();
	Result = Fixed(FloatResult);
	return (Result);
}

Fixed& Fixed::min(Fixed& left, Fixed& right)
{
	if (left.getRawBits() < right.getRawBits())
		return(left);
	return(right);
}

const Fixed& Fixed::min(const Fixed& left, const Fixed& right)
{
	if (left.getRawBits() < right.getRawBits())
		return(left);
	return(right);
}

Fixed& Fixed::max(Fixed& left, Fixed& right)
{
	if (left.getRawBits() > right.getRawBits())
		return(left);
	return(right);
}

const Fixed& Fixed::max(const Fixed& left, const Fixed& right)
{
	if (left.getRawBits() > right.getRawBits())
		return(left);
	return(right);
}


Fixed& Fixed::operator++(void)
{
	this->setRawBits(this->getRawBits() + 1);
	return(*this);
}

Fixed Fixed::operator++(int)
{
	Fixed	prev(*this);
	this->setRawBits(this->getRawBits() + 1);
	return(prev);
}

//____________________________________________________________//

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
