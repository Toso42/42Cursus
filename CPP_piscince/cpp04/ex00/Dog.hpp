/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdi-leo <tcorax42@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 23:18:05 by tdi-leo           #+#    #+#             */
/*   Updated: 2023/02/14 13:17:19 by tdi-leo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP
#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
private:
	Brain* _brain;
public:

	/*	ORTHODOX CANON	*/
	Dog();
	Dog(const Dog& instance);
	Dog& operator=(const Dog& instance);
	~Dog();
	/*	OTHER CONSTRUCTORS	*/
	Dog(std::string _type);
	/*	METHODS	*/
	void	makeSound() const;

};

#endif