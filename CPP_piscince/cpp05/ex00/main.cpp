#include "Bureaucrat.hpp"
#include <iostream>

int main()
{
	Bureaucrat	one;
	Bureaucrat	two("Pippo", 16);
	Bureaucrat	three("Pluto", 10);
	Bureaucrat	four("Topolino", 2);
	Bureaucrat	five("Paperone", 200);
	
	three.demote();
	four.promote();
	std::cout << one << two << three << four << five;
	four.promote();
	return (0);
}