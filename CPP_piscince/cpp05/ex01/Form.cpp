#include "Form.hpp"

Form::Form() : _name("B12"), _is_signed(false), _grade_tosign(15), _grade_toexec(42)
{
	;
}

Form::Form(const Form& F) :  _name("B12"),  _grade_tosign(15), _grade_toexec(42)
{
	this->_is_signed = F.getStatus();
}

Form& Form::operator=(const Form& F)
{
	this->_is_signed = F.getStatus();
	return (*this);
}

Form::~Form()
{
	;
}


std::string Form::getName() const
{
	return(this->_name);
}

bool Form::getStatus() const
{
	return(this->_is_signed);
}

int Form::getGtsign() const
{
	return(this->_grade_tosign);
}

int Form::getGtexec() const
{
	return(this->_grade_toexec);
}

void Form::beSigned(const Bureaucrat& B)
{

	if (B.getGrade() > this->_grade_tosign)
		throw(Form::GradeTooLowException());
	this->_is_signed = true;
}

