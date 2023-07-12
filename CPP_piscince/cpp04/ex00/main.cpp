/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdi-leo <tdi-leo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 11:34:42 by tdi-leo           #+#    #+#             */
/*   Updated: 2023/02/22 11:21:59 by tdi-leo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

// int	main(void)
// {
// 	const Animal* animals[4] = { new Dog(), new Dog(), new Cat(), new Cat() };

// 	for ( int i = 0; i < 4; i++ )
// 		animals[i]->makeSound();
// 	for ( int i = 0; i < 4; i++ )
// 		delete (animals[i]);

// 	WrongCat Error;
// 	const WrongAnimal* ptr = &Error;
	
// 	ptr->makeSound();
// 	return (0);
// }

int	main(void)
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	// std::cout << j->getType() << " " << std::endl;
	// std::cout << i->getType() << " " << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();
	delete (meta);
	delete (j);
	delete (i);

	const WrongAnimal*	wa = new WrongAnimal();
	const WrongAnimal*	wc = new WrongCat();
	// std::cout << wc->getType() << std::endl;
	// std::cout << wa->getType() << std::endl;
	wc->makeSound();
	wa->makeSound();
	delete (wc);
	delete (wa);
	return (0);
}