/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdi-leo <tcorax42@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 11:34:42 by tdi-leo           #+#    #+#             */
/*   Updated: 2023/02/14 13:30:24 by tdi-leo          ###   ########.fr       */
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
	return (0);
}