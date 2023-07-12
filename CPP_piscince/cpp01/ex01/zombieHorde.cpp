/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdi-leo <tdi-leo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 19:36:07 by tdi-leo           #+#    #+#             */
/*   Updated: 2023/01/21 20:11:23 by tdi-leo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name)
{
	Zombie *zombieHorde;
	
	zombieHorde = new Zombie[10];
	//zombieHorde = (Zombie *)malloc(sizeof(Zombie) * 10);
	for (int x = 0; x < N; x++)
	{
//		new (zombieHorde + x) Zombie();
		zombieHorde[x].set_name(name);
		zombieHorde[x].announce();
	}
	return(zombieHorde);
}