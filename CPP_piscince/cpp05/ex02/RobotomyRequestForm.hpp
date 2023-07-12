/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm copy.hpp                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdi-leo <tdi-leo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 13:44:02 by tdi-leo           #+#    #+#             */
/*   Updated: 2023/03/16 14:13:02 by tdi-leo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP
#include <iostream>
#include <fstream>
#include "types.hpp"
#include "AForm.hpp"
#include "Bureaucrat.hpp"

class RobotomyRequestForm : public AForm
{
public:
	RobotomyRequestForm();
	RobotomyRequestForm(const RobotomyRequestForm& F);
	RobotomyRequestForm& operator=(const RobotomyRequestForm& F);
	~RobotomyRequestForm();
	// void				beSigned(const Bureaucrat& B);
	void				action(const Bureaucrat& B) const;

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