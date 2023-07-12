#include "types.hpp"
#include "Intern.hpp"
#include <iostream>

const t_factory Intern::formFactory[Intern::formtypes] = {
	{"ShrubberyCreationForm", &Intern::makeShrubbery},
	{"RobotomyRequestForm", &Intern::makeRobotomy},
	{"PresidentialPardonForm", &Intern::makePardon}
};

Intern::Intern()
{
    ;
}

Intern::Intern(const Intern& instance)
{
    (void)instance;
}

Intern& Intern::operator=(const Intern& instance)
{
    (void)instance;
    return(*this);
}

Intern::~Intern()
{
    
}

AForm* Intern::makeForm(std::string form_name, std::string target)
{
    size_t  foundIndex = this->factoryIndex(form_name);

	if (foundIndex == Intern::formtypes)
	{
		std::cout << "Intern: \" SIR! form "<< form_name << " doesn't exists! \"" << std::endl;
		return (NULL);
	}
	else
	{
		std::cout << "**Intern creates "<< form_name << std::endl;
		return ((this->*(formFactory[foundIndex].methodPointer)) (target));
	}
}

size_t Intern::factoryIndex(std::string form_name)
{
    size_t i;

    for (i = 0; i < this->formtypes; i++)
    {
        if (!form_name.compare(Intern::formFactory[i].form_name))
            break ;
    }
    return(i);
}

AForm* Intern::makeShrubbery(std::string target)
{
    return(new ShrubberyCreationForm(target));
}

AForm* Intern::makeRobotomy(std::string target)
{
    return(new RobotomyRequestForm(target));
}

AForm* Intern::makePardon(std::string target)
{
    return(new PresidentialPardonForm(target));
}
