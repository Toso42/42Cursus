/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongWrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdi-leo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 22:59:33 by tdi-leo           #+#    #+#             */
/*   Updated: 2023/02/20 14:59:00 by tdi-leo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP
#include <iostream>

class WrongAnimal
{

private:
	//nothing
protected:
	std::string	_type;
public:

	/*	ORTHODOX CANON	*/
	WrongAnimal();
	WrongAnimal(const WrongAnimal& instance);
	WrongAnimal& operator=(const WrongAnimal& instance);
	virtual ~WrongAnimal();
	/*	OTHER CONSTRUCTORS */
	WrongAnimal(std::string type);
	/*	METHODS	*/
	void	makeSound() const;

};

#endif