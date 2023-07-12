#include <iostream>
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"



int	main()
{
	Bureaucrat 	A("Pippo", 1);
	Bureaucrat	B("Pluto", 149);
	// Form		F;
	// Bureaucrat 	B("Pippo", 2);
	// Bureaucrat 	C("Pippo", 34);
	ShrubberyCreationForm	F;
	PresidentialPardonForm	P;
	RobotomyRequestForm		R;
	try
	{
		A.execForm(F);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		A.signForm(F);
		A.execForm(F);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	try
	{
		B.signForm(P);
		B.execForm(P);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	try
	{
		A.signForm(P);
		A.execForm(P);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	try
	{
		A.signForm(R);
		A.execForm(R);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	try
	{
		B.signForm(R);
		B.execForm(R);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return(0);
}