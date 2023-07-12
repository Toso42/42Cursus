/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdi-leo <tcorax42@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 22:59:33 by tdi-leo           #+#    #+#             */
/*   Updated: 2023/02/14 11:48:40 by tdi-leo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP
#include <iostream>

class Animal
{

private:
	//nothing
protected:
	std::string	_type;
public:

	/*	ORTHODOX CANON	*/
	Animal();
	Animal(const Animal& instance);
	Animal& operator=(const Animal& instance);
	virtual ~Animal();
	/*	OTHER CONSTRUCTORS */
	Animal(std::string type);
	/*	METHODS	*/
	virtual void	makeSound() const;

};

#endif