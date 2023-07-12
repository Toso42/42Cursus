#include <iostream>
#include "Bureaucrat.hpp"
#include "Form.hpp"

int	main()
{
	Bureaucrat 	A("Pippo", 1);
	Form		F;
	Bureaucrat 	B("Pippo", 2);
	Bureaucrat 	C("Pippo", 34);

	try
	{
		std::cout << "about to promote" << std::endl;
		A.promote();
		std::cout << "about to sign" << std::endl;
		A.signForm(F);
	}
	catch(const Bureaucrat::GradeTooLowException& e)
	{
		std::cerr << e.what() << "\n";
	}
	catch(const Bureaucrat::GradeTooHighException& e)
	{
		std::cerr << e.what() << "\n";
	}
	catch(const Form::GradeTooLowException& e)
	{
		std::cout << B.getName() + " couldn't sign Form " << F.getName() + " because " << e.what() << std::endl;
	}
	std::cout << std::endl;
	try
	{
		std::cout << "about to promote" << std::endl;
		B.promote();
		std::cout << "about to sign" << std::endl;
		B.signForm(F);
	}
	catch(const Bureaucrat::GradeTooLowException& e)
	{
		std::cerr << e.what() << "\n";
	}
	catch(const Bureaucrat::GradeTooHighException& e)
	{
		std::cerr << e.what() << "\n";
	}
	catch(const Form::GradeTooLowException& e)
	{
		std::cout << B.getName() + " couldn't sign Form " << F.getName() + " because " << e.what() << std::endl;
	}
	std::cout << std::endl;
	try
	{
		std::cout << "about to promote" << std::endl;
		C.promote();
		std::cout << "about to sign" << std::endl;
		C.signForm(F);
	}
	catch(const Bureaucrat::GradeTooLowException& e)
	{
		std::cerr << e.what() << "\n";
	}
	catch(const Bureaucrat::GradeTooHighException& e)
	{
		std::cerr << e.what() << "\n";
	}
	catch(const Form::GradeTooLowException& e)
	{
		std::cout << B.getName() + " couldn't sign Form " << F.getName() + " because " << e.what() << std::endl;
	}
}