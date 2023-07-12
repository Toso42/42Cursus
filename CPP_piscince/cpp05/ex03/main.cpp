#include <iostream>
#include <sstream>
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "Intern.hpp"
#include <unistd.h>

#define read_input(ptr, type, msg) do {\
    std::cout << msg << ": ";\
	std::cout << std::endl;\
    if (!(std::cin >> *((type *)(ptr)))) {\
        std::cin.clear();\
        std::cin.ignore(10000, '\n');\
        throw std::invalid_argument("Invalid input");\
    }\
    std::cin.ignore(10000, '\n');\
} while (0)

void	read_string(std::string &str, const char *msg)
{
	do
	{
		std::cout << msg << ": ";
		std::getline(std::cin, str, '\n');
	} while (str.empty());
}

int	main()
{
	std::string	BurName;
	int			BurGrade;
	std::string FormName;
	std::string	FormTarget;
	Intern		SomeRandomIntern;
	bool		repeat = true;
	bool		input_error = false;
	AForm*		newForm;

	while (repeat)
	{
		std::cout << "This is the Bureau's execution center, please provide the following informations: " << std::endl;
		try {
			read_input(&BurName, std::string, "What's the name of the Bureaucrat I am talking with? (write down your name without spaces)");
			}
		catch (const std::exception& e) {
			std::cerr << e.what() << '\n'; 
			repeat = false;
			input_error = true;
			break ;
		}
		try { 
			read_input(&BurGrade, int, "And what's your grade? (again, no spaces)");
			}
		catch(const std::exception& e) {
			std::cerr << e.what() << '\n';
			repeat = false;
			input_error = true;
			break ;
			}
		sleep(1);
		if (input_error == false)
		{
			std::cout << "I am talking to Bureaucrat "<< BurName << " of grade " << BurGrade << std::endl;
			sleep(1);
			std::cout << "I'll check that everything is in order, please wait..." << std::endl << "*You hear some really nasty keystroke sounds*" << std::endl;
			sleep(2);
			try { Bureaucrat AskingBur(BurName, BurGrade); 
			}
			catch(Bureaucrat::GradeTooHighException& e) {
				std::cerr << BurName + ": " << e.what() << '\n';
				break ;
			}
			catch(Bureaucrat::GradeTooLowException& e) {
				std::cerr << BurGrade << " : " << e.what() << '\n';
				break ;
			}
		}
		std::cout << "Permission granted. " << std::endl;
		sleep(1);
		try {
			read_input(&FormName, std::string, "Which Form do you need?");
			}
		catch (const std::exception& e) {
			std::cerr << e.what() << '\n'; 
			repeat = false;
			input_error = true;
			break ;
		}
		try { 
			read_input(&FormTarget, std::string, "And who do we need this Form aimed at? (as always, no whitespaces allowed!)");
			}
		catch(const std::exception& e) {
			std::cerr << e.what() << '\n';
			repeat = false;
			input_error = true;
			break ;
			}
		if (input_error == false)
		{
			std::cout << "I'll have the form handled by our intern, pleas wait..." << std::endl;
			sleep(1);
			newForm = SomeRandomIntern.makeForm(FormName, FormTarget);
			sleep(2);
			if (newForm)
			{
				std::cout << "The receptionist quickly reads through the newly created form..." << std::endl;
				sleep(1);
				std::cout << "Yes, yes, everything's in order. Here's your form, please step back. *Handles the form to you, then procedes to destroy it's copy*" << std::endl;
				delete (newForm);
			}
			else
			{
				std::cout << "The receptionist quickly reads through the newly created form..." << std::endl;
				sleep(1);
				std::cout << "nonono, this ain't right... Sir you'll have to move back in line and try again, please be more careful while compiling your request. *The receptionist waves at the next people in line*" << std::endl;
			}
		}
		std::cout << "NEEEEEEEEEXT!!! *someone quickly passes over you, pushing you aside*" << std::endl << std::endl;
	}
	sleep(2);
	std::cout << "This office is closing for the day, please take a step back. *SLAM*" << std::endl;
	if (input_error == false)
		exit (EXIT_SUCCESS);
	else
		exit (EXIT_FAILURE);
}