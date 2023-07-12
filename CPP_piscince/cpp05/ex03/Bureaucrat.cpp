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
	if (grade <= 0)
		throw(Bureaucrat::GradeTooHighException());
	if (grade > 150)
		throw(Bureaucrat::GradeTooLowException());
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

void Bureaucrat::signForm(AForm& F)
{
	if (this->getGrade() > F.getGtsign())
		throw(AForm::GradeTooLowException());
	F.beSigned(*this);
}

void Bureaucrat::execForm(AForm& F)
{
	if (this->getGrade() > F.getGtexec())
		throw(AForm::GradeTooLowException());
	F.action(*this);
	std::cout << this->getName() << " suxcessfully executed the" << F.getName() << std::endl;
}