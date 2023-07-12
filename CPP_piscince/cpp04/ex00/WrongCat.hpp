/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongWrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdi-leo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 23:18:05 by tdi-leo           #+#    #+#             */
/*   Updated: 2023/02/20 15:02:49 by tdi-leo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP
#include "WrongAnimal.hpp"
#include "Brain.hpp"

class WrongCat : public WrongAnimal
{
private:
	Brain* _brain;
public:

	/*	ORTHODOX CANON	*/
	WrongCat();
	WrongCat(const WrongCat& instance);
	WrongCat& operator=(const WrongCat& instance);
	~WrongCat();
	/*	OTHER CONSTRUCTORS	*/
	WrongCat(std::string _type);
	/*	METHODS	*/
	void	makeSound() const;

};

#endif