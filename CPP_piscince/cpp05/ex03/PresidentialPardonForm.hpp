/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm copy.hpp                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdi-leo <tdi-leo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 13:44:02 by tdi-leo           #+#    #+#             */
/*   Updated: 2023/03/16 14:13:02 by tdi-leo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP
#include <iostream>
#include <fstream>
#include "types.hpp"
#include "AForm.hpp"
#include "Bureaucrat.hpp"

class PresidentialPardonForm : public AForm
{
private:
	std::string	name;
public:
	PresidentialPardonForm();
	PresidentialPardonForm(const PresidentialPardonForm& F);
	PresidentialPardonForm& operator=(const PresidentialPardonForm& F);
	~PresidentialPardonForm();

	PresidentialPardonForm(const std::string name);
	void	action(const Bureaucrat& B) const;

	class GradeTooLowException : public std::exception
	{
	public:
		virtual const char *what() const throw() {
			return("grade is too low!");
		}
	};
	class FormNotSignedException : public std::exception
	{
	public:
		virtual const char *what() const throw() {
			return("form is not signed!");
		}
	};
	class OstreamException : public std::exception
	{
	public:
		virtual const char *what() const throw() {
			return("Error: failed to open ostream.");
		}
	};
};

#endif