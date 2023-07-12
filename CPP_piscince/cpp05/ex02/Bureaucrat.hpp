/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdi-leo <tdi-leo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 13:38:29 by tdi-leo           #+#    #+#             */
/*   Updated: 2023/03/15 19:34:41 by tdi-leo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP
#include "types.hpp"
#include "AForm.hpp"
#include <cstdlib>

class Bureaucrat
{
private:
	std::string	_name;
	int			_grade;
public:
	Bureaucrat();
	Bureaucrat(const Bureaucrat& instance);
	Bureaucrat& operator=(const Bureaucrat& instance);
	~Bureaucrat();

	Bureaucrat(std::string name, int grade);
	std::string const	getName(void) const;
	int					getGrade(void) const;
	void				promote(void);
	void				demote(void);
	void				signForm(AForm& F);
	void				execForm(AForm& F);
	
	//EXCEPTIONS
	class GradeTooHighException : public std::exception
	{
	public:
		virtual const char *what() const throw() {
			return("Error: Grade too High!\n");
		}
	};
	
	class GradeTooLowException : public std::exception
	{
	public:
		virtual const char *what() const throw() {
			return("Error: Grade too Low!\n");
		}
	};
};

std::ostream& operator<<(std::ostream &output, const Bureaucrat &instance);


#endif