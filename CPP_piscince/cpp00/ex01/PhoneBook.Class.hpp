/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.Class.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdi-leo <tcorax42@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 10:30:51 by tdi-leo           #+#    #+#             */
/*   Updated: 2023/01/15 14:13:43 by tdi-leo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_CLASS_HPP
# define PHONEBOOK_CLASS_HPP
//#include <iostream>
#include "Contact.Class.hpp"

class PhoneBook {

public:
	
	PhoneBook(void);
	~PhoneBook(void);

	// void	set_input(std::string input);
	int			add_subroutine(void);
	void		search_subroutine(void);
	void		expand_contact(Contact *match);
	std::string	format_string(std::string field);

private:
	std::string	current_input;
	Contact		_Contacts[8];
	int			_current_index;
};

void do_exit(void);

#endif