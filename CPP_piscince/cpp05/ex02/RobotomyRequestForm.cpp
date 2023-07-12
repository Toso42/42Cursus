#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", false, 72, 45)
{
	;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& F) : AForm(F)
{
	;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& F)
{
	this->AForm::operator=(F);
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	;
}

void RobotomyRequestForm::action(const Bureaucrat& B) const
{
	if (B.getGrade() > this->getGtexec())
		throw(RobotomyRequestForm::GradeTooLowException());
	if (this->getStatus() == false)
		throw(RobotomyRequestForm::FormNotSignedException());
	std::cout << "*Bzzzzzz BwriirrrrrrrZZZZzzzZZZzzin*" << std::endl;
	if (std::rand() % 2)
		std::cout << B.getName() << " was robotomized!!!" << std::endl;
	else
		std::cout << B.getName() << "'s robotomization failed... a real shame." << std::endl;
}

