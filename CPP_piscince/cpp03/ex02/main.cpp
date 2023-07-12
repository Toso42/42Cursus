/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdi-leo <tdi-leo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 17:10:50 by tdi-leo           #+#    #+#             */
/*   Updated: 2023/02/13 18:21:45 by tdi-leo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int	main(void)
{
	ScavTrap	Tizio("Tizio");
	ScavTrap	Caio("Caio");
	FragTrap	Sempronio("Sempronio");
	
	Tizio.attack(Caio);
	Caio.attack(Sempronio);
	Sempronio.beRepaired(10);
	Tizio.guardGate();
	Sempronio.highFivesGuys();
	Sempronio.attack(Tizio);
	return (0);
}