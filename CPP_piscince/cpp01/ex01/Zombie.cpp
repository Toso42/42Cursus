/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdi-leo <tdi-leo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 19:36:11 by tdi-leo           #+#    #+#             */
/*   Updated: 2023/01/21 19:44:30 by tdi-leo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Zombie.hpp"

Zombie::Zombie(void)
{
//	this->announce();
}

Zombie::~Zombie(void)
{
	std::cout << "\e[1m  *" << this->_name << " was killed. Again.*\e[0m" << std::endl;
}

void Zombie::announce(void)
{
	std::cout << this->_name << ": \"BraiiiiiiinnnzzzZ...\"" << std::endl;
}

void Zombie::set_name(std::string name)
{
	this->_name = name;
}
