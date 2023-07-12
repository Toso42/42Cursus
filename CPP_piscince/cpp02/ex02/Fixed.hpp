#ifndef FIXED_HPP
# define FIXED_HPP
# include <iostream>
#include <cmath>

class Fixed
{
public:
	//CONSTRUCTORS / DECONSTRUCTORS
	Fixed();
	Fixed(const int value);
	Fixed(const float value);
	Fixed(const Fixed &ptr);
	~Fixed();
	//COMPARISON OPERATOR OVERLOADS
	bool	operator==(const Fixed& instance);
	bool	operator!=(const Fixed& instance);
	bool	operator>(const Fixed& instance);
	bool	operator>=(const Fixed& instance);
	bool	operator<(const Fixed& instance);
	bool	operator<=(const Fixed& instance);
	//ARITHMETICAL OPERATOR OVERLOADS
	Fixed&	operator=(const Fixed& instance);
	Fixed	operator+(const Fixed& instance);
	Fixed	operator-(const Fixed& instance);
	Fixed	operator*(const Fixed& instance);
	Fixed	operator/(const Fixed& instance);

	Fixed&	operator++(void);
	Fixed	operator++(int);

	static Fixed&	min(Fixed& left, Fixed& right);
	static const Fixed&	min(const Fixed& left, const Fixed& right);
	static Fixed&	max(Fixed& left, Fixed& right);
	static const Fixed&	max(const Fixed& left, const Fixed& right);


	//PUBLIC METHODS
	int		getRawBits(void) const;
	void	setRawBits(const int value);
	int		toInt(void) const;
	float	toFloat(void) const;
	int		getBits(void) const;
private:
	int					_value;
	static const int 	_bits = 8;
};

std::ostream& operator<<(std::ostream &output, const Fixed &instance);

#endif