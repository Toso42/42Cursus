/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.Class.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdi-leo <tcorax42@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 16:55:31 by tdi-leo           #+#    #+#             */
/*   Updated: 2023/01/15 14:16:18 by tdi-leo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_CLASS_HPP
# define CONTACT_CLASS_HPP

#include <iostream>

class Contact {

public:
		
		Contact(void);

		bool		is_valid_stream(void);

		void		set_used(void);
		bool		is_used(void);
		//------------------------//
		void		set_index(int index);
		int			get_index(void);
		//------------------------//
		void		set_fname(void);
		std::string	get_fname(void);
		void		set_lname(void);
		std::string	get_lname(void);
		void		set_nname(void);
		std::string	get_nname(void);
		void		set_tel(void);
		std::string	get_tel(void);
		void		set_secret(void);
		std::string	get_secret(void);

private:

		int			_index;
		bool		_is_used;
		std::string _first_name;
		std::string _last_name;
		std::string _nickname;
		std::string _tel_number;
		std::string _secret;
		
};

#endif