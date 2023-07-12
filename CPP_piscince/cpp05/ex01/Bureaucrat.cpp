#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("Hermes"), _grade(34)
{
	;
}

Bureaucrat::Bureaucrat(const Bureaucrat& instance)
{
	this->_grade = instance.getGrade();
	this->_name = instance.getName();
}

Bureaucrat::Bureaucrat(std::string name, int grade)
{
	this->_name = name;
	try
	{
		if (grade <= 0)
			throw(Bureaucrat::GradeTooHighException());
		if (grade > 150)
			throw(Bureaucrat::GradeTooLowException());
	}
	catch(GradeTooHighException& e)
	{
		std::cerr << this->getName() + ": " << e.what() << '\n';
		return ;
	}
	catch(GradeTooLowException& e)
	{
		std::cerr << this->getName() + ": " << e.what() << '\n';
		return ;
	}
	this->_grade = grade;
}

Bureaucrat::~Bureaucrat()
{
	;
}

std::string const Bureaucrat::getName(void) const
{
	return(this->_name);
}

int Bureaucrat::getGrade(void) const
{
	return(this->_grade);
}

void Bureaucrat::promote(void)
{
	if ((this->getGrade() - 1) <= 0)
		throw(Bureaucrat::GradeTooHighException());
	this->_grade--;
}

void Bureaucrat::demote(void)
{
	if ((this->getGrade() + 1) > 150)
		throw(Bureaucrat::GradeTooLowException());
	this->_grade++;
}

std::ostream& operator<<(std::ostream &output, const Bureaucrat &instance)
{
	output << instance.getName() << std::endl;
	return(output);
}

void Bureaucrat::signForm(Form& F)
{
	if (this->getGrade() > F.getGtsign())
		throw(Form::GradeTooLowException());
	F.beSigned(*this);
}