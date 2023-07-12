/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdi-leo <tdi-leo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 15:33:05 by tdi-leo           #+#    #+#             */
/*   Updated: 2023/01/21 20:16:24 by tdi-leo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>

Zombie* newZombie( std::string name );
void randomChump( std::string name );
Zombie* zombieHorde( int N, std::string name);

int	main(void)
{
	Zombie *Horde;
	std::string	signal_gesture;

	std::cout << "\"Experiment 8 commenced. Waiting for horde deployment signal...\"";
	std::getline (std::cin, signal_gesture, '\n');
	Horde = zombieHorde(10, "TestSubject");
	std::cout << "\"Everything goin according to plan. Give us a signal to terminate the Horde...\"";
	std::getline (std::cin, signal_gesture, '\n');
	delete[] Horde;
}