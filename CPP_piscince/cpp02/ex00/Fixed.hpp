#ifndef FIXED_HPP
# define FIXED_HPP
# include <iostream>

class Fixed
{
public:
	Fixed();
	Fixed(const Fixed &ptr);
	Fixed& operator=(const Fixed& instance);
	~Fixed();

	int		getRawBits(void) const;
	void	setRawBits(const int value);
private:
	int 				_value;
	static const int 	_bits = 8;
};




#endif