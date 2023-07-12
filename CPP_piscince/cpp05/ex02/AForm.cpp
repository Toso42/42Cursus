#include "AForm.hpp"

AForm::AForm() : _name("B12"), _is_signed(false), _grade_tosign(15), _grade_toexec(42)
{
	;
}

AForm::AForm(const AForm& F) : _name(F._name), _is_signed(F._is_signed), _grade_tosign(F._grade_tosign), _grade_toexec(F._grade_toexec)
{
	this->_is_signed = F.getStatus();
}

AForm::AForm(std::string name, bool sign, int gts, int gte) : _name(name), _is_signed(sign), _grade_tosign(gts), _grade_toexec(gte)
{
	;
}

AForm& AForm::operator=(const AForm& F)
{
	this->_is_signed = F.getStatus();
	return (*this);
}

AForm::~AForm()
{
	;
}

std::string AForm::getName() const
{
	return(this->_name);
}

bool AForm::getStatus() const
{
	return(this->_is_signed);
}

int AForm::getGtsign() const
{
	return(this->_grade_tosign);
}

int AForm::getGtexec() const
{
	return(this->_grade_toexec);
}

void AForm::beSigned(const Bureaucrat& B)
{

	if (B.getGrade() > this->_grade_tosign)
		throw(AForm::GradeTooLowException());
	this->_is_signed = true;
}

