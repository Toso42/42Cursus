#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", false, 25, 5)
{
	;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& F) : AForm(F)
{
	;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& F)
{
	this->AForm::operator=(F);
	return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	;
}

void PresidentialPardonForm::action(const Bureaucrat& B) const
{
	if (B.getGrade() > this->getGtexec())
		throw(PresidentialPardonForm::GradeTooLowException());
	if (this->getStatus() == false)
		throw(PresidentialPardonForm::FormNotSignedException());
	std::cout << B.getName() << " has been grant an official pardon warrant by Zaphod Beeblebrox" << std::endl;
}

