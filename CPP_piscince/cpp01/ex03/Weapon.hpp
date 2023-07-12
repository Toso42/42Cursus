/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdi-leo <tcorax42@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 18:20:59 by tdi-leo           #+#    #+#             */
/*   Updated: 2023/01/25 19:54:00 by tdi-leo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
#define WEAPON_HPP
#include <iostream>

class Weapon {
private:
	std::string 	_type;
public:
	Weapon(std::string type);
	~Weapon();

	void			setType(std::string w_type);
	std::string 	&getType(void);
};
#endif
