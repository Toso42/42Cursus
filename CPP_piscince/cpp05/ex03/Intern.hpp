#ifndef INTERN_HPP
# define INTERN_HPP
# include <iostream>
# include "types.hpp"
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"

typedef AForm*(Intern::*makeFormType)(const std::string form_name);

typedef struct s_factory 
{
  const std::string form_name;
  makeFormType methodPointer;

} t_factory;

class Intern
{
private:
	//factory (array of structs prototyped above, number of form types, method to retrieve the correct index in the factory)
	static const size_t formtypes = 3;
	static const t_factory formFactory[formtypes]; // Since all Interns share the form methods, factory is defined static so that it gets instanciated only once for all Intern instances.
	size_t factoryIndex(std::string form_name);
	// methods to create form types, returning a pointer to new instance
	AForm* makeShrubbery(std::string target);
	AForm* makeRobotomy(std::string target);
	AForm* makePardon(std::string target);

public:
	Intern();
	Intern(const Intern& instance);
	Intern& operator=(const Intern& instance);
	~Intern();

	AForm* makeForm(std::string form_name, std::string target);
};

#endif