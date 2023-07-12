/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdi-leo <tcorax42@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 15:33:05 by tdi-leo           #+#    #+#             */
/*   Updated: 2023/01/15 17:15:34 by tdi-leo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>

Zombie* newZombie( std::string name );
void randomChump( std::string name );

int	main(void)
{
	Zombie *Subject1;
	std::string	signal_gesture;

	Subject1 = newZombie("Subject1");
	randomChump("Subject2");

	std::cout << "\"Experiment 7: everything going according to plan, Sir.\nGive us a signal to execute Order 42 on Subject 1...\"";
	std::getline (std::cin, signal_gesture, '\n');
	
	delete Subject1;
}