#ifndef FIXED_HPP
# define FIXED_HPP
# include <iostream>
#include <cmath>

class Fixed
{
public:
	Fixed();
	Fixed(const int value);
	Fixed(const float value);
	Fixed(const Fixed &ptr);
	Fixed& operator=(const Fixed& instance);
	~Fixed();

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