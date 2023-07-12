/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdi-leo <tdi-leo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 17:10:50 by tdi-leo           #+#    #+#             */
/*   Updated: 2023/02/13 17:56:17 by tdi-leo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main( void )
{
	ScavTrap	Gigino("gigino");
	ScavTrap	Gigetto("gigetto");
	ClapTrap	Gigiotto("gigiotto");

	Gigino.attack(Gigetto);
	Gigetto.attack(Gigiotto);
	Gigiotto.beRepaired(10);
	Gigino.guardGate();
	Gigiotto.attack("Gigino");
	Gigino.takeDamage(0);
	return (0);
}