/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdi-leo <tdi-leo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 17:10:50 by tdi-leo           #+#    #+#             */
/*   Updated: 2023/02/13 20:13:22 by tdi-leo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int	main(void)
{
	ScavTrap	Tizio("Tizio");
	ScavTrap	Caio("Caio");
	FragTrap	Sempronio("Sempronio");
	DiamondTrap	Diamante("Diamante");
	DiamondTrap	Null;
	
	Tizio.attack(Caio);
	Caio.attack(Sempronio);
	Sempronio.beRepaired(10);
	Tizio.guardGate();
	Sempronio.highFivesGuys();
	Sempronio.attack(Tizio);
	Diamante.whoAmI();
	Null.whoAmI();
	return (0);
}