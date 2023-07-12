/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdi-leo <tcorax42@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 15:15:48 by tdi-leo           #+#    #+#             */
/*   Updated: 2023/01/15 16:37:25 by tdi-leo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP
#include <iostream>

class Zombie {

private:

	std::string	_name;

public:

	Zombie(std::string name);
	~Zombie(void);

	void	announce(void);
//	void	_set_name(std::string name);
};

#endif
