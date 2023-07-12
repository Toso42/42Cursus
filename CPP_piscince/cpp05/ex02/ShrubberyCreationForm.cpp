#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", false, 145, 137)
{
	;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& F) : AForm(F)
{
	;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& F)
{
	this->AForm::operator=(F);
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	;
}

void ShrubberyCreationForm::action(const Bureaucrat& B) const
{
	std::ofstream towrite;
	std::string	  filename;
	if (B.getGrade() > this->getGtexec())
		throw(ShrubberyCreationForm::GradeTooLowException());
	if (this->getStatus() == false)
		throw(ShrubberyCreationForm::FormNotSignedException());
	filename = B.getName() + "_shrubbery";
	towrite.open(filename.c_str());
	if (towrite.rdstate() == std::ios_base::badbit)
		throw(ShrubberyCreationForm::OstreamException());
	towrite << "ASCII tree			ASCII tree \nASCII tree			ASCII tree \nASCII tree				ASCII tree \nASCII tree			ASCII tree \nASCII tree	ASCII tree \n ASCII tree		ASCII tree \n" << std::endl;
}

