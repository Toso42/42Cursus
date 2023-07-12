/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdi-leo <tcorax42@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 23:18:05 by tdi-leo           #+#    #+#             */
/*   Updated: 2023/02/14 13:32:36 by tdi-leo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP
#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal
{
private:
	Brain* _brain;
public:

	/*	ORTHODOX CANON	*/
	Cat();
	Cat(const Cat& instance);
	Cat& operator=(const Cat& instance);
	~Cat();
	/*	OTHER CONSTRUCTORS	*/
	Cat(std::string _type);
	/*	METHODS	*/
	void	makeSound() const;

};

#endif