/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdi-leo <tdi-leo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 13:44:02 by tdi-leo           #+#    #+#             */
/*   Updated: 2023/03/15 15:15:16 by tdi-leo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP
#include <iostream>
#include "types.hpp"
#include "Bureaucrat.hpp"

class Form
{
private:
	const std::string	_name;
	bool				_is_signed;
	const int			_grade_tosign;
	const int			_grade_toexec;
public:
	Form();
	Form(const Form& F);
	Form& operator=(const Form& F);
	~Form();
	void		beSigned(const Bureaucrat& B);

	std::string	getName() const;
	bool		getStatus() const;
	int			getGtsign() const;
	int			getGtexec() const;
	
	class GradeTooLowException : public std::exception
	{
	public:
		virtual const char *what() const throw() {
			return("grade is too low!");
		}
	};
};



#endif