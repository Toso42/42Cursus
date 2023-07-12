/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdi-leo <tcorax42@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 18:25:28 by tdi-leo           #+#    #+#             */
/*   Updated: 2023/01/25 19:14:40 by tdi-leo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"
#include <iostream>

Weapon::Weapon(std::string type)
{
	this->setType(type);
}

Weapon::~Weapon()
{
}

void Weapon::setType(std::string w_type)
{
	_type = w_type;
}

std::string& Weapon::getType(void)
{
	std::string &typeREF = this->_type;

	return(typeREF);
}
