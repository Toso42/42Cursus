/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdi-leo <tdi-leo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 11:34:42 by tdi-leo           #+#    #+#             */
/*   Updated: 2023/02/15 12:41:14 by tdi-leo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int	main(void)
{
	const Animal* animals[4] = { new Dog(), new Dog(), new Cat(), new Cat() };

	for ( int i = 0; i < 4; i++ )
		animals[i]->makeSound();
	for ( int i = 0; i < 4; i++ )
		delete (animals[i]);
	
//	Animal	test;
	return (0);
}