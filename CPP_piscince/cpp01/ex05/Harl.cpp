/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdi-leo <tdi-leo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 14:39:30 by tdi-leo           #+#    #+#             */
/*   Updated: 2023/02/08 17:22:32 by tdi-leo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Harl.hpp"

const 	Harl::t_harlmethod_holder Harl::holder[5] = {
		{"debug", &Harl::debug},
		{"info", &Harl::info},
		{"warning", &Harl::warning},
		{"error", &Harl::error},
		{"", &Harl::dumb}
	};

void Harl::debug(void)
{
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl;
}

void Harl::info(void)
{
	std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}

void Harl::warning(void)
{
	std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << std::endl;
}

void Harl::error(void)
{
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

void Harl::dumb(void)
{
	// nothing
}

int Harl::index_getter(std::string level)
{
	int x = 0;
	for (; x < 4 ; x++)
	{
		if (holder[x].name.compare(level) == 0)
			return (x);
	}
	return(x);
}

Harl::Harl()
{
	
}

Harl::~Harl()
{
	
}

void Harl::complain(std::string level)
{
	(this->*holder[index_getter(level)].ptr)();
	// metodo pubblico che scorre l'array e ritorna il puntatore a funzione appropriata.
}
