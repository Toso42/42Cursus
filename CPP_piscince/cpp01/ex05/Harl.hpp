/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdi-leo <tdi-leo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 14:32:29 by tdi-leo           #+#    #+#             */
/*   Updated: 2023/02/08 17:19:41 by tdi-leo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP
#include <string.h>
#include <iostream>

// typedef int pippo;

// pippo var;


class Harl
{
	typedef void(Harl::*harlmethod)(void);

	typedef struct t_harlmethod_holder {
		const std::string name;
		harlmethod	ptr;
	}	t_harlmethod_holder;

private:

	void	debug(void);
	void	info(void);
	void	warning(void);
	void	error(void);
	void	dumb(void);
	int		index_getter(std::string level);
	static const t_harlmethod_holder	holder[5];

public:

	Harl();
	~Harl();
	void complain(std::string level);
};
#endif