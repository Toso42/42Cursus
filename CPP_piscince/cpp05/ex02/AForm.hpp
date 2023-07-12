/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdi-leo <tdi-leo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 13:44:02 by tdi-leo           #+#    #+#             */
/*   Updated: 2023/03/15 16:15:06 by tdi-leo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP
#include <iostream>
#include "types.hpp"
#include "Bureaucrat.hpp"

class AForm
{
private:
	const std::string	_name;
	bool				_is_signed;
	const int			_grade_tosign;
	const int			_grade_toexec;
public:
	AForm();
	AForm(std::string _name, bool sign, int gts, int gte);
	AForm(const AForm& F);
	AForm& 		operator=(const AForm& F);
	virtual 	~AForm();
	void		beSigned(const Bureaucrat& B);

	virtual std::string	getName() const;
	virtual bool		getStatus() const;
	virtual int			getGtsign() const;
	virtual int			getGtexec() const;
	virtual void		action(const Bureaucrat& B) const = 0;
	
	class GradeTooLowException : public std::exception
	{
	public:
		virtual const char *what() const throw() {
			return("grade is too low!");
		}
	};
};

#endif