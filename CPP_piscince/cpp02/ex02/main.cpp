#include <iostream>
#include <stdio.h>
#include "Fixed.hpp"

int main( void ) {
	// Fixed a;
	// Fixed const b( 10 );
	// Fixed const c( 42.42f );
	// Fixed const d( b );
	// a = Fixed( 1234.4321f );
	// std::cout << "a is " << a << std::endl;
	// std::cout << "b is " << b << std::endl;
	// std::cout << "c is " << c << std::endl;
	// std::cout << "d is " << d << std::endl;
	// std::cout << "a is " << a.toInt() << " as integer" << std::endl;
	// std::cout << "b is " << b.toInt() << " as integer" << std::endl;
	// std::cout << "c is " << c.toInt() << " as integer" << std::endl;
	// std::cout << "d is " << d.toInt() << " as integer" << std::endl;
	Fixed	a(1);
	Fixed	b(2.5f);
	Fixed	c = a + b;
	std::cout << "a + b = " << c << std::endl;
	std::cout << "a + b = " << a + b << std::endl;
	std::cout << "1 + 2.5 = " << 1 + 2.5f << std::endl;
	//~c();
	c = a - b;
	std::cout << "a - b = " << c << std::endl;
	std::cout << "a - b = " << a - b << std::endl;
	std::cout << "1 - 2.5 = " << 1 - 2.5f << std::endl;
	c = a * b;
	std::cout << "a * b = " << c << std::endl;
	std::cout << "a * b = " << a * b << std::endl;
	std::cout << "1 * 2.5 = " << 1 * 2.5f << std::endl;
	c = a / b;
	std::cout << "a / b = " << c << std::endl;
	std::cout << "a / b = " << a / b << std::endl;
	std::cout << "1 / 2.5 = " << 1 / 2.5f << std::endl;

	std::cout << "max is: "<< Fixed::max(a, b) << std::endl;
	std::cout << "min is: " << Fixed::min(a, b) << std::endl;
	
	c = a;
	std::cout << "c++ = " << c++ << std::endl;
	c = a;
	std::cout << "++c= " << ++c << std::endl;
	// std::cout << sizeof("¯🦀 ") << "¯🦀 " << strlen("¯🦀 ");
	// printf("¯🦀");jkjkjk
	return 0;
}

